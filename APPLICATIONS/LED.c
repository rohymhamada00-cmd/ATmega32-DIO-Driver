
#include<avr/io.h>
#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

void main(){
	 DIO_voidSetPinDirection  (DIO_PORTA ,  DIO_PIN0 ,  DIO_PIN_OUTPUT); //access portA -> PIN0 ass a output pin
	 DIO_voidSetPinDirection  (DIO_PORTA ,  DIO_PIN1 ,  DIO_PIN_OUTPUT);

	 while(1){
		 DIO_voidSetvalue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		 _delay_ms(1000);
		 DIO_voidSetvalue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		 _delay_ms(1000);
		 DIO_voidTogglePinValue(DIO_PORTA, DIO_PIN1);
		 _delay_ms(250);
	 }


}
