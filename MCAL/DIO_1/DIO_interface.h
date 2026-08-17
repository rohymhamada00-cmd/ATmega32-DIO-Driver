/*
 * DIO_interface.h
 * Layer : MCAL
 * SWC : DIO/GPIO
 *  Created on: Aug 17, 2026
 *      Author: VICTUS
 */

#ifndef _DIO_INTERFACE_H_  //file gaurd name

#define _DIO_INTERFACE_H_

typedef enum 
{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;


//DIRECTION THIRD ARGUMENT 
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0  

//status of the pin
#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0  

//PORT fisrt argument
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//PIN second argument
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3 
#define DIO_PIN4 4
#define DIO_PIN5 5 
#define DIO_PIN6 6 
#define DIO_PIN7 7


DIO_ErrorStatus DIO_voidSetPinDirection  (U8 Copy_U8PORT , U8 Copy_U8PIN , U8 Copy_U8Direction);
DIO_ErrorStatus DIO_voidSetvalue         (U8 Copy_U8PORT , U8 Copy_U8PIN , U8 Copy_U8Value    );
DIO_ErrorStatus DIO_voidTogglePinValue   (U8 Copy_U8PORT , U8 Copy_U8PIN                      );
DIO_ErrorStatus DIO_GetValue             (U8 Copy_U8PORT , U8 Copy_U8PIN , U8* Copy_U8Value   );

//------------------------------------------------
DIO_ErrorStatus DIO_voidSetPortDirection  (U8 Copy_U8PORT  , U8 Copy_U8Direction);
DIO_ErrorStatus DIO_voidSetPortValue      (U8 Copy_U8PORT   , U8 Copy_U8Value   );
DIO_ErrorStatus DIO_enumTogglePortValue   (U8 Copy_u8PORT                       );
DIO_ErrorStatus   DIO_GetPortValue        (U8 Copy_U8PORT,U8* Copy_u8Value      );
#endif
