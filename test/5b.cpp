#include <iostream>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	if(argc==3){
		link(argv[1],argv[2]);
	}else {
		symlink(argv[2],argv[3]);
	}
	system("ls -al");
}