#include "lathe.h"
#include "stm32f1xx_hal.h"

int lathe_speeds[] = {1, 10, 100, 1000};
static int speed_x_idx = 0;
static int speed_y_idx = 0;


void lathe_toggle_speed_x(lathe_t *p_lathe) {
	speed_x_idx = (speed_x_idx+1) % (sizeof(lathe_speeds)/sizeof(lathe_speeds[0]));
	p_lathe->speed_x = lathe_speeds[speed_x_idx];
}

void lathe_toggle_speed_y(lathe_t *p_lathe){
	speed_y_idx = (speed_y_idx+1) % (sizeof(lathe_speeds)/sizeof(lathe_speeds[0]));
	p_lathe->speed_y = lathe_speeds[speed_y_idx];
}


void lathe_start_x(lathe_t *p_lathe, int dir) {
	if(dir > 0) {
		HAL_GPIO_WritePin( GPIOB, GPIO_PIN_4, 1 );

	} else {
		HAL_GPIO_WritePin( GPIOB, GPIO_PIN_4, 0 );

	}
	  HAL_TIM_PWM_Start(p_lathe->p_timer_x, TIM_CHANNEL_1);
}

void lathe_start_y(lathe_t *p_lathe, int dir) {
	if(dir > 0) {
		HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, 1 );

	} else {
		HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, 0 );

	}
	  HAL_TIM_PWM_Start(p_lathe->p_timer_y, TIM_CHANNEL_1);
}

void lathe_stop_x(lathe_t *p_lathe) {
	  HAL_TIM_PWM_Stop(p_lathe->p_timer_x, TIM_CHANNEL_1);
}

void lathe_stop_y(lathe_t *p_lathe) {
	  HAL_TIM_PWM_Stop(p_lathe->p_timer_y, TIM_CHANNEL_1);
}
