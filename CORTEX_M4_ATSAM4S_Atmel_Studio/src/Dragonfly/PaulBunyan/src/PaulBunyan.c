/*
 * PaulBunyan.c
 *
 * Created: 9/13/2014 2:32:57 PM
 *  Author: Conrad
 */ 

#include "asf.h"
#include "ioport.h"

#include "FreeRTOS.h"
#include "task.h"

#include "PaulBunyan.h"


void PaulBunyanTask( void *pvParameters )
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