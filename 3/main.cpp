#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,const char *argv[]){
	int fd;
	struct flock lock;
	char buf[256];
	if(argc!=2){
		return 0;
	}
	fd=open(argv[1],O_RDWR);
	if(fcntl(fd,F_GETLK,&lock)>=0){
		return 0;
	}

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_END;
	lock.l_start=0;
	lock.l_len=100;

	if(fcntl(fd,F_SETLK,&lock)>=0){
		printf("The file is locked by %d",lock.l_pid);
		lseek(fd,-50,SEEK_END);
		printf("Contents of file are");
		if(read(fd,buf,sizeof(buf))){
			printf("%s",buf);
		}
	}

	lock.l_type = F_UNLCK;
	if(fcntl(fd,F_UNLCK,&lock)>=0){
		printf("File is unlocked");
	}
	return 0;
}