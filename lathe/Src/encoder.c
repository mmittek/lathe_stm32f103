#include "encoder.h"




void encoder_gpio_event(encoder_t *p_encoder, GPIO_TypeDef *port, uint32_t pin) {
	if(p_encoder->event_handler == NULL) return;

	int state_a = HAL_GPIO_ReadPin(p_encoder->port_a, p_encoder->pin_a);
	int state_b = HAL_GPIO_ReadPin(p_encoder->port_b, p_encoder->pin_b);
	int state_btn = HAL_GPIO_ReadPin(p_encoder->port_btn, p_encoder->pin_btn);

	int event = -1;

	if((port == p_encoder->port_a && pin == p_encoder->pin_a) || (port == p_encoder->port_b && pin == p_encoder->pin_b)) {
		if( state_a && !state_b ) { // forward
			event = ENCODER_BACKWARD;

		} else if(!state_a && state_b) { // backward
			event = ENCODER_FORWARD;
		}
	} else if(port == p_encoder->port_btn && pin == p_encoder->pin_btn) {
	}

	if(event != -1) {
		p_encoder->event_handler(p_encoder, event);
	}

}
