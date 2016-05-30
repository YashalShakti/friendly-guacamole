#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
int main(int argc,char *argv[]){
	int fd;
	struct flock lock;
	char buff[256];

	fd=open(argv[1],O_RDWR);

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_END;
	lock.l_start = SEEK_END - 100;
	lock.l_len = 100;
	
	if (fcntl(fd,F_SETLK,&lock)==-1){
		cout<<"The file is locked\n";
	}else {
		cout << "Locking the file now\n";	
		lseek(fd,-100,SEEK_END);
		read(fd,buff,sizeof(buff));
		cout<<buff;
	}
	lock.l_type = F_UNLCK;
	if(fcntl(fd,F_SETLK,&lock)>=0){
		cout<<"tada";
	}
}