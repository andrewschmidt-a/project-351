
#include <stdio.h>
#include <sys\alt_stdio.h>
#include <sys\alt_irq.h>
#include <sys\alt_timestamp.h>
#include <sys\alt_alarm.h>
alt_alarm alarm ;

void my_interrupt_handler(){
//printf("handler\n");
}

void initialize_alarm(){
	if(alt_alarm_start(&alarm, alt_ticks_per_second(), my_interrupt_handler, NULL) != 0){
			printf("ERROR WITH TIMER");
		}
}
