
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void printChar(char str[]){
	setbuf(stdout,NULL);
	for(int j=0;j<6;j++)
	for(int i=0;i<strlen(str);i++){
		putc(str[i],stdout);
	}
}

int main(){
	if(fork()==0){
		printChar("OUTPUT IS FROM CHILD\n");
	}else{
		printChar("output is from parent\n");
	}
	_exit(0);
}
