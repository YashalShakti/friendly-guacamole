#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
using namespace std;
int main(int argc, char const *argv[]){
	if(argc!=2 && argc!=3){
		cout<<"Error";
		return -1;
	}
	int fd;
	char buff[256];
	mkfifo(argv[1],S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO);
	if(argc==2){
		fd=open(argv[1],O_RDONLY);
		while(read(fd,buff,sizeof(buff))){
			cout<<buff;
		}
	}else{
		fd=open(argv[1],O_WRONLY);
		write(fd,argv[2],strlen(argv[2]));
	}
	close(fd);
	return 0;
}