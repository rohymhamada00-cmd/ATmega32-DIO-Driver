/*
 * DIO_programe.c
 * Layer : MCAL
 * SWC : DIO/GPIO
 *  Created on: Aug 17, 2026
 *      Author: VICTUS
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"DIO_interface.h"
#include"DIO_private.h"
#include"DIO_configure.h"

/*this DIO_voidSetPinDirection function make u change the direction of the port [input / output]
**1st argument Copy_U8PORT -> [POARTA , PORTB , PORTC , PORTD]
**2nd argument Copy_U8PIN -> [PIN1 .... PIN7]
**3rd argument Copy_U8Direction -> choose if you want it output or input
**return its status 
*/
DIO_ErrorStatus DIO_voidSetPinDirection  (U8 Copy_U8PORT , U8 Copy_U8PIN , U8 Copy_U8Direction)
{
	//make sure that arguments are valids
	DIO_ErrorStatus Enum_status = DIO_OK;
	if((Copy_U8PORT <= DIO_PORTD) && (Copy_U8PIN <= DIO_PIN7)){
	if(Copy_U8Direction == DIO_PIN_OUTPUT)
	{
		switch(Copy_U8PORT){
			case DIO_PORTA: SET_BIT(DDRA , Copy_U8PIN); break;
			case DIO_PORTB: SET_BIT(DDRB , Copy_U8PIN); break;
			case DIO_PORTC: SET_BIT(DDRC , Copy_U8PIN); break;
			case DIO_PORTD: SET_BIT(DDRD , Copy_U8PIN); break;
		}
	}
	else if(Copy_U8Direction == DIO_PIN_INPUT)
	{
		switch(Copy_U8PORT)
		{
			case DIO_PORTA: CLEAR_BIT(DDRA , Copy_U8PIN); break;
			case DIO_PORTB: CLEAR_BIT(DDRB , Copy_U8PIN); break;
			case DIO_PORTC: CLEAR_BIT(DDRC , Copy_U8PIN); break;
			case DIO_PORTD: CLEAR_BIT(DDRD , Copy_U8PIN); break;
			
		}
		
	}
	else
	{
		//in case of error is in PORTID or PINID
		Enum_status = DIO_NOK;
	}
	
	}
	return Enum_status;

}
/*
this DIO_voidSetvalue function allow you to access a value on determine pin 
**1st argument Copy_U8PORT -> [POARTA , PORTB , PORTC , PORTD]
**2nd argument Copy_U8PIN -> [PIN1 .... PIN7]
**return its status 
*/
DIO_ErrorStatus DIO_voidSetvalue(U8 Copy_U8PORT , U8 Copy_U8PIN , U8 Copy_U8Value    )
{
	//make sure that arguments are valids
	DIO_ErrorStatus Enum_status = DIO_OK;
	if((Copy_U8PORT <= DIO_PORTD) && (Copy_U8PIN <= DIO_PIN7)){
		if(Copy_U8Value == DIO_PIN_HIGH)
	{
		switch(Copy_U8PORT){
			case DIO_PORTA: SET_BIT(PORTA , Copy_U8PIN); break;
			case DIO_PORTB: SET_BIT(PORTB , Copy_U8PIN); break;
			case DIO_PORTC: SET_BIT(PORTC , Copy_U8PIN); break;
			case DIO_PORTD: SET_BIT(PORTD , Copy_U8PIN); break;
		}
	}
	else if(Copy_U8Value == DIO_PIN_LOW)
	{
		switch(Copy_U8PORT)
		{
			case DIO_PORTA: CLEAR_BIT(PORTA , Copy_U8PIN); break;
			case DIO_PORTB: CLEAR_BIT(PORTB , Copy_U8PIN); break;
			case DIO_PORTC: CLEAR_BIT(PORTC , Copy_U8PIN); break;
			case DIO_PORTD: CLEAR_BIT(PORTD , Copy_U8PIN); break;
			
		}
		
	}
	}
	else
	{
		//in case of error is in PORTID or PINID
		Enum_status = DIO_NOK;
	}	
	return Enum_status;

}
/*
this DIO_GetValue function allow you to read the pin across PIN register by access it in a pointer 
**1st argument Copy_U8PORT -> [POARTA , PORTB , PORTC , PORTD]
**2nd argument Copy_U8PIN -> [PIN1 .... PIN7]
**return its status 
*/
DIO_ErrorStatus DIO_GetValue(U8 Copy_U8PORT , U8 Copy_U8PIN , U8* Copy_U8Value)
{
	DIO_ErrorStatus Enum_status = DIO_OK;
	if((Copy_U8Value != 0) &&  (Copy_U8PORT <= DIO_PORTD) && (Copy_U8PIN <= DIO_PIN7)){
		
		switch(Copy_U8PORT)
		{
			case DIO_PORTA: *Copy_U8Value = GET_BIT(PINA , Copy_U8PIN); break;
			case DIO_PORTB: *Copy_U8Value = GET_BIT(PINB , Copy_U8PIN); break;
			case DIO_PORTC: *Copy_U8Value = GET_BIT(PINC , Copy_U8PIN); break;
			case DIO_PORTD: *Copy_U8Value = GET_BIT(PIND , Copy_U8PIN); break;
			
		}
	}
	else
	{
		//in case of error is in PORTID or PINID
		Enum_status = DIO_NOK;
	}
	return Enum_status ;
	
}
/*
this DIO_voidTogglePinValue function Toggle the value of the Pin
**1st argument Copy_U8PORT -> [POARTA , PORTB , PORTC , PORTD]
**2nd argument Copy_U8PIN -> [PIN1 .... PIN7]
**return its status 
*/
DIO_ErrorStatus DIO_voidTogglePinValue   (U8 Copy_U8PORT , U8 Copy_U8PIN)
{
		DIO_ErrorStatus Enum_status = DIO_OK;
		if((Copy_U8PORT <= DIO_PORTD) && (Copy_U8PIN <= DIO_PIN7)){
		switch(Copy_U8PORT)
		{
			case DIO_PORTA: TOGGLE_BIT(PORTA , Copy_U8PIN); break;
			case DIO_PORTB: TOGGLE_BIT(PORTB , Copy_U8PIN); break;
			case DIO_PORTC: TOGGLE_BIT(PORTC , Copy_U8PIN); break;
			case DIO_PORTD: TOGGLE_BIT(PORTD , Copy_U8PIN); break;
			
		}
		}
		else
		{
			//in case of error is in PORTID or PINID
			Enum_status = DIO_NOK;
			
		}
		return Enum_status;

}

//-------------------------------------------------------------------------

/*
this DIO_voidSetPortDirection function set the direction of the port
**1st argument Copy_U8PORT -> [POARTA , PORTB , PORTC , PORTD]
return its status
*/
DIO_ErrorStatus DIO_voidSetPortDirection(U8 Copy_U8PORT  , U8 Copy_U8Direction)
{
	//make sure arguments are valid
	DIO_ErrorStatus Enum_status = DIO_OK;
	if(Copy_U8PORT <= DIO_PORTD){
		switch(Copy_U8PORT)
		{
			case DIO_PORTA: DDRA = Copy_U8Direction; break;
			case DIO_PORTB: DDRB = Copy_U8Direction; break;
			case DIO_PORTC: DDRC = Copy_U8Direction; break;
			case DIO_PORTD: DDRD = Copy_U8Direction; break;
	
		}
	}
	else{
		Enum_status = DIO_NOK;
	}
	return Enum_status;

}

DIO_ErrorStatus DIO_voidSetPortValue(U8 Copy_U8PORT   , U8 Copy_U8Value)
{
	//make sure arguments are valid
	DIO_ErrorStatus Enum_status = DIO_OK;
	if(Copy_U8PORT <= DIO_PORTD){
	switch(Copy_U8PORT)
	{
			case DIO_PORTA: PORTA = Copy_U8Value; break;
			case DIO_PORTB: PORTB = Copy_U8Value; break;
			case DIO_PORTC: PORTC = Copy_U8Value; break;
			case DIO_PORTD: PORTD = Copy_U8Value; break;
	
	}
	}
	else
	{
		Enum_status = DIO_NOK;
	}
	return Enum_status;
}
/*
this DIO_GetPortValue make you Read the Value of the Port
**1st argument Copy_U8PORT -> [POARTA , PORTB , PORTC , PORTD]
**2ed argument the address of Copy_u8Value that the value be stored in 
return the status 
*/

DIO_ErrorStatus DIO_GetPortValue(U8 Copy_U8PORT , U8* Copy_u8Value)
{
	DIO_ErrorStatus Enum_status = DIO_OK;
	if((Copy_U8PORT <= DIO_PORTD) && (Copy_u8Value !=0)) {
		switch(Copy_U8PORT)
	{
			case DIO_PORTA: *Copy_u8Value = PINA ; break;
			case DIO_PORTB: *Copy_u8Value = PINB ; break;
			case DIO_PORTC: *Copy_u8Value = PINC ; break;
			case DIO_PORTD: *Copy_u8Value = PIND ; break;
	}
	}
	else
	{
		Enum_status = DIO_NOK;
	}
	return Enum_status;
}

/*
 *  This  DIO_enumTogglePortValueF unction Toggle value on Port
 * Parameters :
 *   =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumTogglePortValue (U8 Copy_u8PORT)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK ;

    if (Copy_u8PORT <= DIO_PORTD)
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA : PORTA = ~PORTA ;
            break ;
            case DIO_PORTB : PORTB = ~PORTB ;
            break ;
            case DIO_PORTC : PORTC = ~PORTC ;
            break ;
            case DIO_PORTD : PORTD = ~PORTD ;
            break ;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState ;
}
