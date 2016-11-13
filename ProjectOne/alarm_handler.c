
#include <stdio.h>
#include <sys\alt_stdio.h>
#include <sys\alt_irq.h>
#include <sys\alt_timestamp.h>
#include <sys\alt_alarm.h>
#include <header.h>
int from_handler = 0;
alt_alarm alarm ;
void my_interrupt_handler(){
printf("handler\n");
from_handler = 1;
}

void initialize_alarm(){
	if(alt_alarm_start(&alarm, alt_ticks_per_second(), my_interrupt_handler, NULL) != 0){
			printf("ERROR WITH TIMER");
		}
}
