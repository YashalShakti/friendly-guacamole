#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc,char *argv[]){
	int status;
	if ( ! fork() )
		execl("/bin/sh","sh","-c",argv[1],NULL);
	wait(&status);
	if ( WEXITSTATUS(status) )
		printf("Error in command %s !! Try again\n",argv[1]);
	return 0;
}