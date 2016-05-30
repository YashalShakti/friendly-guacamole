#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
	pid_t pid;
	cout<<"Parents process p1 has ppid "<<getppid()<<endl;
	cout<<"Parent process p1 has pid "<<getpid()<<endl;
	
	if((pid=fork())==0){
	
		cout<<"\nChild process c1 has ppid "<<getppid()<<endl;
		cout<<"Child process has pid "<<getpid()<<endl;
	
		if((pid=fork())==0){		
		sleep(2);
		cout<<"\nChild process c2 has ppid "<<getppid()<<endl;
		cout<<"Grand child process has pid "<<getpid()<<endl;
			_exit(0);
		}else{	
			_exit(0);
		}
	}else{
		waitpid(pid,NULL,0);
		_exit(0);
	}
}

/*int main() {
	pid_t pid;
	if ((pid = fork()) == 0) {
		if ((pid = fork()) > 0)
			exit(0);
		sleep(2);
		printf("second child, parent pid = %d\n", getppid()); exit(0);
	}
	if (waitpid(pid, NULL, 0) != pid)
	printf("waitpid error");
	exit(0);
} */
