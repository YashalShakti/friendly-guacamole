#include <iostream>
using namespace std;
#include <unistd.h>
int main(){
	#ifdef _POSIX_CHOWN_RESTRICTED
		cout<<"Supported 1"<<endl;
#endif
	#ifdef _POSIX_VDISABLE
		cout<<"Supported 2"<<endl;
#endif

	#ifdef _POSIX_NO_TRUNC
		cout<<"Supported 3"<<endl;
#endif

	#ifdef _POSIX_JOB_CONTROL
		cout<<"Supported 4"<<endl;
#endif

	#ifdef _POSIX_SAVED_IDS
		cout<<"Supported 5"<<endl;
#endif

}