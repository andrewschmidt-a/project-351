#include <header.h>
struct thread{
	int id;
	int stack_address;
	int stack_size;
	int stack_pointer;
	int state;
	int priority;
};

int numthreads =0;
struct thread threads[12];
void initialize_thread(int num_thread){

		threads[num_thread].stack_size = 700;
		threads[num_thread].stack_address = malloc(threads[num_thread].stack_size);
		threads[num_thread].stack_pointer = threads[num_thread].stack_address-threads[num_thread].stack_size/2;
		threads[num_thread].state = 0;
		threads[num_thread].priority=0;
}
int current_thread = 0;
int my_scheduler(int sp){//round robin
	if(current_thread == 0){
		printf("Zero\n");
	}
	threads[current_thread].stack_pointer= sp;
	current_thread = (current_thread+1)%12;
	alt_printf("test:%x\n",current_thread );
	//return threads[current_thread].stack_pointer;
	return sp;
}
void destroy_thread(){

}
void create_thread(){

}
/*
void join_thread(struct thread mythread){
	while(mythread.state = "not dead")
}*/
