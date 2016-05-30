#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	pid_t pid;
	if((pid=fork())==0){
	    cout<<"\nProcess id of parent:\t"<<getppid();
	    cout<<"\nProcess id of child:\t"<<getpid()<<"\n\n";
        _exit(0);
	}
	char cmd[50];
	sleep(20);
	sprintf(cmd,"ps -l %d",pid);
	system(cmd);
	_exit(0);
}