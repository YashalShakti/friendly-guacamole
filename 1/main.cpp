#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <unistd.h>
#include <iostream>
using namespace std;
int main(){
	long res;
	if((res=sysconf(_SC_CLK_TCK))>=0){
		cout<<"\nClock "<<res;
	}

	if((res=sysconf(_SC_CHILD_MAX))>=0){
		cout<<"\nMax child "<<res;
	}

	if((res=sysconf(_SC_OPEN_MAX))>=0){
		cout<<"\nMax open "<<res;
	}

	if((res=pathconf("/",_PC_PATH_MAX))>=0){
		cout<<"\nMax path "<<res;
	}

	if((res=pathconf("/",_PC_NAME_MAX))>=0){
		cout<<"\nMax name "<<res;
	}
}