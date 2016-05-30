#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void action(int s){
	system("date");
}
int main(){
	while(1){
		signal(SIGALRM,action);
		alarm(2);
		pause();
	}
}