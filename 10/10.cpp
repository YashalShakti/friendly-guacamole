#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void alarm_handler(int s){
	system("date");
}
int main(){
	while(1){
	 	signal(SIGALRM,alarm_handler);
		alarm(2);
		pause();
	}
	return 0;
}
