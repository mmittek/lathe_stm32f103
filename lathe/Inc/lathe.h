#ifndef _LATHE_H_
#define _LATHE_H_

#include <stdint.h>
#include <stdbool.h>
#include "stm32f1xx_hal.h"



typedef struct {
	bool x_moving;
	bool y_moving;
	int speed_x;
	int speed_y;

	TIM_HandleTypeDef *p_timer_x;
	TIM_HandleTypeDef *p_timer_y;
}lathe_t;


void lathe_start_x(lathe_t *p_lathe, int dir);
void lathe_stop_x(lathe_t *p_lathe);
void lathe_start_y(lathe_t *p_lathe, int dir);
void lathe_stop_y(lathe_t *p_lathe);
void lathe_toggle_speed_x(lathe_t *p_lathe);
void lathe_toggle_speed_y(lathe_t *p_lathe);


#endif // _LATHE_H_
