
#include<avr/io.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "../HAL/SSD_driver/SSD_interface.h"
#include<util/delay.h>

int main(void)
{
	
	SSD_Type SSD1 = {SSD_common_cathod , SSD_PORTC , SSD_PORTD , SSD_PIN0};
	SSD_Type SSD2 = {SSD_common_cathod , SSD_PORTC , SSD_PORTD , SSD_PIN1};
	
	SSD_voidInitDataPort(SSD1);
	while(1)
	{
		for(U8 i = 0 ; i < 100 ; i++)
		{
			U8 units = i % 10 ;
			U8 tens  = i / 10 ; 
			for(U8 j = 0 ; j < 50 ; j++)
			{
				SSD_voidEnable(SSD1);
				SSD_voidDisable(SSD2);
				SSD_voidSendNumber(SSD1, units);
				_delay_ms(5);   

				// الشاشة الثانية
				SSD_voidDisable(SSD1);
				SSD_voidEnable(SSD2);
				SSD_voidSendNumber(SSD2, tens);
				_delay_ms(5);
			}
		}

		
		

		
	
	}
	return 0 ;
}