#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>


void (*print_hello)(const char *);

int load_lib(){

	void *lib_pointer = dlopen("./libHello.so", RTLD_LAZY);
	if(NULL == lib_pointer){
		return 0;
	}
	
	print_hello = (void (*)(const char *))dlsym(lib_pointer, "print_hello");
	if(NULL == print_hello){
		return 0;
	}
	return 1;
}

int main(void){
	if(load_lib()){
		print_hello("ariel");
	}
	else{
		printf("Error in loading library\n");
	}
	
	return 0;
}
