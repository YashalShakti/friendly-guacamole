#include <string.h>
#include <stdio.h>
#include <unistd.h>
int pc(char a[]){
	setbuf(stdout,NULL);
	for(int j=0;j<6;j++)
	for(int i=0;i<strlen(a);i++)
		putchar(a[i]);
}

int main(){
	if(fork()==0)
		return pc("ouput from child\n");
	return pc("OUTPUT FROM PARENT\n");
}