#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <stdint.h>
#include "gpio.h"


typedef enum {
	ENCODER_PUSH,
	ENCODER_RELASE,
	ENCODER_FORWARD,
	ENCODER_BACKWARD,
} encoder_event_t;

struct encoder_s;

typedef void (*encoder_event_handler_t)(struct encoder_s *p_encoder, encoder_event_t event_t);

struct encoder_s{
	uint32_t					pin_a;
	GPIO_TypeDef					*port_a;
	uint32_t					pin_b;
	GPIO_TypeDef					*port_b;
	uint32_t					pin_btn;
	GPIO_TypeDef					*port_btn;
	encoder_event_handler_t		event_handler;
};

typedef struct encoder_s encoder_t;


void encoder_gpio_event(encoder_t *p_encoder, GPIO_TypeDef *port, uint32_t pin);

#endif // ENCODER_H
