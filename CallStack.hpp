#ifndef CALL_STACK_HPP
#define CALL_STACK_HPP
#include <cstring>
#include <cstdio>
#include <cstdlib>

//This is a stack but really not, all we do is just push onto. No popping, only peaking.
//If we go over our size we will just treat it as a circular buffer.
class CallStack{

public:
	char **buffer;
	char ** top;
	char ** bottom;
	int buffer_size;
	int nr_callers;

	CallStack(){
		buffer = (char **) malloc(sizeof(char *) * 5);
		
		top = NULL;
		bottom = NULL;
		nr_callers = 0;
		buffer_size = 5;

		for(int i=0;i < buffer_size;i++){
			buffer[i] = (char *) malloc(sizeof(char) * 64);
			buffer[i][0] = 0;
		}
	}

	bool push(const char * new_caller){
		if(!new_caller) return false;

		if(!top){
			top = buffer;
			strncpy(*top, new_caller, 64);

			bottom = top;
			goto end_push;
		}

		if(nr_callers >= buffer_size){
			top++;
			bottom++;
			int index = ((top - buffer) % buffer_size );
			top = buffer + index;
			strncpy(*top, new_caller, 64);

			return true;
		}

		top++;
		strncpy(*top, new_caller, 64);
		
end_push:
		nr_callers++;
		return true;
	}
	
	char * peek(){
		if(nr_callers == 0) return NULL;
		return *(top);
	}

	char * peekn(int n){
		if(n > buffer_size || n >= nr_callers) return NULL;
		
		if(top < bottom){
			int tmp = (top - buffer) - n;
			if(tmp < 0) return *((buffer + buffer_size) + tmp);
			return *(buffer + tmp);
		}else{
			return *(top - n);
		}

	}
	
	void print(){
		printf("=====================\n");
		for(int i = 0; i < nr_callers; i++){
			printf("%p\t%s", buffer + i, buffer[i]);
			if((buffer + i) == top) printf("<-- Top\n");
			else if(( buffer + i) == bottom) printf("<-- Bottom\n");
			else printf("\n");
		}
		printf("=====================\n");
	}
};

#endif
