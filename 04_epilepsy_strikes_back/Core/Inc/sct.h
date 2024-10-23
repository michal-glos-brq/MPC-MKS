/*
 * sct.h
 *
 *  Created on: Oct 9, 2024
 *      Author: xglosm01
 */

#ifndef INC_SCT_H_
#define INC_SCT_H_

#include "main.h"

void sct_init();
void sct_led(uint32_t value);
void sct_value(uint16_t value, uint8_t led);
void sct_value_decimals(uint16_t value, uint8_t led, uint8_t decimal);

#endif /* INC_SCT_H_ */
