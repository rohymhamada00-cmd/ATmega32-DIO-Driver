 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
/*
 * SSD_programe.c
 * Layer: HAL.
 * SWC  : 7 Segment Display.
 * Created on: Aug 18, 2026.
 * Author: Eng.Mohamed Elnashar.
 */
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 

 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
 #include"DIO_interface.h"
#include"SSD_private.h"
 #include"SSD_interface.h"
 
// Array containing the binary values for digits from 0 to 9
static U8 Local_ssd_nums[10] = SSD_array;
 
// Function to initialize the 7-Segment data port and set it as output (0xFF)
void SSD_voidInitDataPort(SSD_Type SSD_configuration)
{
	DIO_voidSetPortDirection( SSD_configuration.DATA_PORT , 0xFF);
}

// Function to send the number to be displayed, automatically inverting bits based on the display type (Cathode or Anode)
void SSD_voidSendNumber(SSD_Type SSD_configuration , U8 Copy_Number)
{
	// If the display is Common Cathode, send the value as is
	if(SSD_configuration.TYPE == SSD_common_cathod)
	{
		DIO_voidSetPortValue(SSD_configuration.DATA_PORT, Local_ssd_nums[Copy_Number] );
	}
	// If the display is Common Anode, invert the value (~bit-wise NOT) because segments turn on with Low logic
	else if(SSD_configuration.TYPE == SSD_common_anode)
	{
		DIO_voidSetPortValue(SSD_configuration.DATA_PORT , ~(Local_ssd_nums[Copy_Number]));
	}
}

// Function to enable and turn on the 7-Segment via the enable pin
void SSD_voidEnable(SSD_Type SSD_configuration)
{
	// For Cathode, set the pin direction to output then send Low to turn it on
	if(SSD_configuration.TYPE == SSD_common_cathod)
	{
		DIO_voidSetPinDirection(SSD_configuration.ENABLE_PORT, SSD_configuration.ENABLE_PIN , DIO_PIN_HIGH);
		DIO_voidSetvalue(SSD_configuration.ENABLE_PORT, SSD_configuration.ENABLE_PIN , DIO_PIN_LOW);
	}
	// For Anode, set the pin direction to output then send High to turn it on
	else if(SSD_configuration.TYPE == SSD_common_anode)
	{
		DIO_voidSetPinDirection(SSD_configuration.ENABLE_PORT , SSD_configuration.ENABLE_PIN , DIO_PIN_HIGH);
		DIO_voidSetvalue(SSD_configuration.ENABLE_PORT , SSD_configuration.ENABLE_PIN , DIO_PIN_HIGH);
	}
}
 
// Function to disable and turn off the 7-Segment via the enable pin
void SSD_voidDisable(SSD_Type SSD_configuration)
{
	// For Cathode, send High to turn it off
	if(SSD_configuration.TYPE == SSD_common_cathod)
	{
		DIO_voidSetPinDirection (SSD_configuration.ENABLE_PORT, SSD_configuration.ENABLE_PIN , DIO_PIN_HIGH);
		DIO_voidSetvalue(SSD_configuration.ENABLE_PORT, SSD_configuration.ENABLE_PIN , DIO_PIN_HIGH);
	}
	// For Anode, send Low to turn it off
	else if(SSD_configuration.TYPE == SSD_common_anode)
	{
		DIO_voidSetPinDirection(SSD_configuration.ENABLE_PORT , SSD_configuration.ENABLE_PIN , DIO_PIN_HIGH);
		DIO_voidSetvalue(SSD_configuration.ENABLE_PORT , SSD_configuration.ENABLE_PIN , DIO_PIN_LOW);
	}
}
 
