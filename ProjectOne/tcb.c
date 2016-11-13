#include <header.h>
#include <stdio.h>
#include <sys\alt_stdio.h>
#include <sys\alt_irq.h>
#include <sys\alt_timestamp.h>
#include <sys\alt_alarm.h>
int current_thread = 0;
struct thread{
	int id;
	int *stack_address;
	int stack_size;
	int *stack_pointer;
	int state;
	int priority;
};
extern from_handler;
int check_interrupt(){
	if(from_handler == 1){
	printf("check:%x\n",current_thread );}
	return from_handler;
}
void my_thread(){
	printf("This is my thread\n");
	int i = 0;
	for(i=0; i<255; i++){

	}
}
void destroy_thread(){
	prototype_os();
}
int numthreads =0;
struct thread threads[12];

void initialize_thread(int num_thread){

		threads[num_thread].stack_size = 700;
		threads[num_thread].stack_address = malloc(threads[num_thread].stack_size);
		threads[num_thread].stack_pointer = threads[num_thread].stack_address-threads[num_thread].stack_size/2;
		threads[num_thread].state = 0;
		threads[num_thread].priority=0;
		threads[num_thread].stack_pointer[0] = &my_thread;
		threads[num_thread].stack_pointer[18] = &my_thread;
}
int my_scheduler(int *sp){//round robin
	from_handler = 0;
	if(current_thread == 0){
		printf("Zero\n");
	}
	//threads[current_thread].stack_pointer= sp;
	current_thread = (current_thread+1)%12;
	alt_printf("test:%d\n",current_thread );
	int temp = sp[0];
	threads[current_thread].stack_pointer[0] =  temp;
	//initialize_alarm();
	return threads[current_thread].stack_pointer;
	//return sp;
}

/*
void join_thread(struct thread mythread){
	while(mythread.state = "not dead")
}*/
