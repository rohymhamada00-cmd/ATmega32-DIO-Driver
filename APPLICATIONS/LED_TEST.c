/*
 * applicatio name : 3 leds with 3 diff times delay;
 *
 *  Created on: Aug 18, 2026
 *      Author: VICTUS
 */


#include<avr/io.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "../HAL/LED_driver/LED_interface.h"
#include<util/delay.h>

void main()
{
	LED_Type led1 = {LED_PORTA, LED_PIN0, Active_HIGH};
	LED_Type led2 = {LED_PORTA, LED_PIN1, Active_HIGH};
	LED_Type led3 = {LED_PORTA, LED_PIN2, Active_HIGH};
	LED_voidInit(led1);
	LED_voidInit(led2);
	LED_voidInit(led3);

		s8 counter = 0;
	while(1){
		counter++;
		if(counter % 1 ==0){LED_voidToggle(led1);}
		if(counter % 2 ==0){LED_voidToggle(led2);}
		if(counter % 3 ==0){LED_voidToggle(led3);}

		_delay_ms(1000);

	}


}
