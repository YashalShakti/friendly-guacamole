#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc,char *argv[]){
	pid_t pid = fork();
	if(pid==0){
		execl("/bin/sh","","-c",argv[1],NULL);
	}
	waitpid(pid,NULL,0);
	return 0;
}