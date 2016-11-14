#include <header.h>
#include <stdio.h>
#include <sys\alt_stdio.h>
#include <sys\alt_irq.h>
#include <sys\alt_timestamp.h>
#include <sys\alt_alarm.h>
// disable an interrupt
#define DISABLE_INTERRUPTS() { \
asm("wrctl status, zero"); \
}
// enable an interrupt
#define ENABLE_INTERRUPTS() { \
asm("movi et, 1"); \
asm("wrctl status, et"); \
}
struct thread{
	alt_u32 id;
	alt_u32 *stack_address;
	alt_u32 stack_size;
	alt_u32 *stack_pointer;
	alt_u32 state;
	alt_u32 priority;
};

alt_u32 current_thread = 0;
extern from_handler;
int check_interrupt(){
	if(from_handler == 1){
	printf("check:%x\n",current_thread );}
	return from_handler;
}
void my_thread(){
	alt_printf("This is my thread\n");
	int i = 0;
	for(i=0; i<6; i++){

	}
}
void destroy_thread(){
	//ENABLE_INTERRUPTS();
	while(1){
		int i = 0;
		for(i=0; i<2555; i++){

		}
	}
}
int numthreads =0;
struct thread threads[12];

void initialize_thread(int num_thread){

		threads[num_thread].stack_size = 700;
		threads[num_thread].stack_address = malloc(threads[num_thread].stack_size);
		threads[num_thread].stack_pointer = threads[num_thread].stack_address+threads[num_thread].stack_size-19;
		threads[num_thread].state = 0;
		threads[num_thread].priority=0;
		threads[num_thread].stack_pointer[-1] = threads[num_thread].stack_address+threads[num_thread].stack_size;
		threads[num_thread].stack_pointer[0] = &destroy_thread;
		threads[num_thread].stack_pointer[18] = &my_thread; //72
		threads[num_thread].stack_pointer[17] = 1;
}
alt_u32 my_scheduler(alt_u32 *sp){//round robin
	from_handler = 0;
	//current_thread = sp[19];
	if(current_thread == 0){
		alt_printf("Zero\n");
	}
	//threads[current_thread].stack_pointer= sp;
	current_thread = (current_thread+1)%12;
	alt_printf("test:%x\n",current_thread );
	//int temp = sp[0];
	threads[current_thread].stack_pointer[0] =  &destroy_thread;
	threads[current_thread].stack_pointer[19] = current_thread;
	//initialize_alarm();
	reset_alarm(alt_ticks_per_second()*1);
	return (void *)threads[current_thread].stack_pointer;

	//return sp;
}

/*
void join_thread(struct thread mythread){
	while(mythread.state = "not dead")
}*/
