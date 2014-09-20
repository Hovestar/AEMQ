/*
 * BatMan.c
 *
 * Created: 9/20/2014 3:21:57 PM
 *  Author: Hovestar
 */ 

#include "asf.h"
#include "ioport.h"

#include "FreeRTOS.h"
#include "task.h"

#include "BatMan.h"


void BatManTask( void *pvParameters )
{
	static unsigned int count = 0;
	
	while(1)
	{
		/* Blink LED to verify that task is entered */
		taskENTER_CRITICAL();
		{
			if(!count)
			{
				ioport_toggle_pin_level(LED_0_PIN);
			}
			count = (count + 1)%20000;		
		}
		taskEXIT_CRITICAL();
	}
}
