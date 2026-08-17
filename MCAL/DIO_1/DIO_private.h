/*
 * DIO_private.h
 * Layer : MCAL
 * SWC : DIO/GPIO
 *  Created on: Aug 17, 2026
 *      Author: VICTUS
 */

#ifndef _DIO_PRIVATE_H_  /*file gaurd name*/
#define _DIO_PRIVATE_H_

/*GROUP A */
#define PORTA   *((volatile U8*) 0x3B)
#define DDRA    *((volatile U8*) 0x3A)
#define PINA    *((volatile U8*) 0x39)

/*GROUP B */
#define PORTB   *((volatile U8*) 0x38)
#define DDRB    *((volatile U8*) 0x37)
#define PINB    *((volatile U8*) 0x36)

/*GROUP C */
#define PORTC   *((volatile U8*) 0x35)
#define DDRC    *((volatile U8*) 0x34)
#define PINC    *((volatile U8*) 0x33)

/*GROUP D */
#define PORTD   *((volatile U8*) 0x32)
#define DDRD    *((volatile U8*) 0x31)
#define PIND    *((volatile U8*) 0x30)



#endif