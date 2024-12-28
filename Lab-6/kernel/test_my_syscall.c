#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(void){
	printf("Trying to call system call.\n");
	long status = syscall(386);
	printf("My syscall_new returned %ld\n",status);
	return 0;
}
