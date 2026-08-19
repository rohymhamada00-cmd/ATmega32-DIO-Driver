 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
/*
 * LED_interface.h
 * Layer: HAL.
 * SWC  : LED.
 * Created on: Aug 18, 2026.
 * Author: Eng.Mohamed Elnashar.
 */
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 
 
 //file gaurd name
#ifndef _LED_INTERFACE_H_
#define _LEd_INTERFACE_H_


//LED Initillization
typedef struct
{
	U8 PORT;
	U8 PIN;
	U8 State;
}LED_Type;

//PORT fisrt argument
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

//PIN second argument
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3 
#define LED_PIN4 4
#define LED_PIN5 5 
#define LED_PIN6 6 
#define LED_PIN7 7

//ACTIVE STATUS
#define Active_HIGH 1
#define Active_LOW  0



//functions

void LED_voidInit  (LED_Type LED_configuration);
void LED_voidON    (LED_Type LED_configuration);
void LED_voidOFF   (LED_Type LED_configuration);
void LED_voidToggle(LED_Type LED_configuration);

#endif
