 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
/*
 * LED_programe.c
 * Layer: HAL.
 * SWC  : LED.
 * Created on: Aug 18, 2026.
 * Author: Eng.Mohamed Elnashar.
 */
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 

 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
#include "DIO_interface.h"
 #include"LED_interface.h"
 
 /*
 this LED_voidInit initialize the pin which connected to the led 
 parameters => struct which has [port , pin , status of the led]
 return => void
 */
 
 void LED_voidInit(LED_Type LED_configuration)
 {
	 DIO_voidSetPinDirection(LED_configuration.PORT , LED_configuration.PIN , DIO_PIN_OUTPUT);
 }

  /*
 this LED_voidON Set the led high 
 parameters => struct which has [port , pin , status of the led]
 return => void
 */
 void LED_voidON(LED_Type LED_configuration)
 {
	 if(LED_configuration.State == Active_HIGH )
	 {
		 DIO_voidSetvalue(LED_configuration.PORT , LED_configuration.PIN , Active_HIGH);
	 }
	 else if(LED_configuration.State == Active_LOW)
	 {
		 DIO_voidSetvalue(LED_configuration.PORT , LED_configuration.PIN , Active_LOW);
	 }
 }
 
   /*
 this LED_voidON Set the led low 
 parameters => struct which has [port , pin , status of the led]
 return => void
 */
 void LED_voidOFF(LED_Type LED_configuration)
 {
	 if(LED_configuration.State == Active_HIGH )
	 {
		 DIO_voidSetvalue(LED_configuration.PORT , LED_configuration.PIN , Active_LOW);
	 }
	 else if(LED_configuration.State == Active_LOW)
	 {
		 DIO_voidSetvalue(LED_configuration.PORT , LED_configuration.PIN , Active_HIGH);
	 }
 }
 
   /*
 this LED_voidON Toggle the state of the led
 parameters => struct which has [port , pin , status of the led]
 return => void
 */
 
 void LED_voidToggle(LED_Type LED_configuration)
 {
	DIO_voidTogglePinValue   (LED_configuration.PORT , LED_configuration.PIN);
 }
 
 
 
