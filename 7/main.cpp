#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(){
	if(fork()==0){
	    std::cout<<"\nProcess id of parent:\t"<<getppid();
	    std::cout<<"\nProcess id of child:\t"<<getpid()<<"\n\n";
        _exit(0);
	}
	sleep(1);
	system("ps all | head -1");
	system("ps all | grep a.out");
	_exit(0);
}