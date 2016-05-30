#include <stdlib.h>
#include <unistd.h>
int main(){
	if(fork()==0){
		return 0;
	}
	sleep(0.5);
	system("ps all");
}