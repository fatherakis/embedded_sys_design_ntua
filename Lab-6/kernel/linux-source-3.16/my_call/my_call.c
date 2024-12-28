#include <linux/kernel.h>

asmlinkage long syscall_new(void){
	int team = 30;
	printk(KERN_ALERT "Greetings from kernel and team %d\n",team);
	return 0;
}
