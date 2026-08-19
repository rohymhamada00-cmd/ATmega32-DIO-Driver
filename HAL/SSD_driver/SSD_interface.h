 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
/*
 * SSD_interface.h
 * Layer: HAL.
 * SWC  : 7 segment display.
 * Created on: Aug 18, 2026.
 * Author: Eng.Mohamed Elnashar.
 */
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------
 
 
 //file gaurd name
#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_


//SSD TYPES
#define SSD_common_cathod  0 
#define SSD_common_anode   1


//SSD Initillization
typedef struct
{
	U8 TYPE;          // SD_common_cathod or SSD_common_anode
	U8 DATA_PORT;     // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	U8 ENABLE_PORT;   // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	U8 ENABLE_PIN;	  // SSD_PIN0 , SSD_PIN1 ,SSD_PIN2 , SSD_PIN3 , SSD_PIN4 , SSD_PIN5 , SSD_PIN6 , SSD_PIN7  
	
} SSD_Type;

//PORTS
#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3

//PINS
#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3 
#define SSD_PIN4 4
#define SSD_PIN5 5 
#define SSD_PIN6 6 
#define SSD_PIN7 7

//ACTIVE STATUS
#define Active_HIGH 1
#define Active_LOW  0



//functions

void SSD_voidInitDataPort  (SSD_Type SSD_configuration);
void SSD_voidEnable        (SSD_Type SSD_configuration);
void SSD_voidDisable       (SSD_Type SSD_configuration);
void SSD_voidSendNumber    (SSD_Type SSD_configuration , U8 Copy_Number);

#endif
