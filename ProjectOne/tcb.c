
struct thread{
	int id;
	int stack_address;
	int stack_size;
	int stack_pointer;
	int state;
	int priority;
};

int numthreads =0;
struct thread threads[50];
void initialize_thread(struct thread *mythread){

	(*mythread).stack_size = 700;
	(*mythread).stack_address = malloc((*mythread).stack_size);
	(*mythread).stack_pointer = (*mythread).stack_address-(*mythread).stack_size/2;
	(*mythread).state = 0;
	(*mythread).priority=0;
	numthreads++;
}
int current_thread = 0;
int my_scheduler(int sp){//round robin
	threads[current_thread].stack_pointer= sp;
	current_thread = (current_thread+1)%50;
	return threads[current_thread].stack_pointer;
}
void destroy_thread(){

}
void create_thread(){

}
/*
void join_thread(struct thread mythread){
	while(mythread.state = "not dead")
}*/
