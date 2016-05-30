#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	if(!fork()){
		if(!fork()){
			sleep(1);
            return 0;
		}
		return 0;	
	}
	wait(NULL);
    system("ps -o pid,ppid,state,command | egrep '[a].out|[P]ID'");
}