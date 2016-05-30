#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
using namespace std;
int main(int argc,char *argv[]){
	int fd;
	char buff[256];
	mkfifo(argv[1], 4607);
	if(argc==2){
		fd = open(argv[1],O_RDONLY);
		while(read(fd,buff,sizeof(buff))){
			cout<<buff<<endl;
		}
	}else if(argc==3){
		fd=open(argv[1],O_WRONLY);
		write(fd,argv[2],strlen(argv[2]));
	}
	close(fd);
	return 0;
}