#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <iostream>

int main(int argc,const char *argv[]){
	int fd;
	struct flock lock;
	char buf[256];
	
	if(argc!=2){
		return 0;
	}
	
        fd=open(argv[1],O_RDWR);
	
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_END;
	lock.l_start= SEEK_END - 100;
	lock.l_len=100;

        printf("press enter to set lock\n");
        getchar();
	if(fcntl(fd,F_SETLK,&lock)>=0){
		printf("The file now locked by %d",lock.l_pid);
		lseek(fd,-50,SEEK_END);
		printf("Contents of file are");
		while(read(fd,buf,sizeof(buf))){
			std::cout<<buf;
		}
	}else {
		printf("File is already locked");
		return 0;
	}
	getchar();
	lock.l_type = F_UNLCK;
	if(fcntl(fd,F_SETLKW,&lock)>=0){
		printf("File is unlocked");
	}
	return 0;
}
