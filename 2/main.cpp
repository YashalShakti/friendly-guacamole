#define _POSIX_SOURCE
#define _POSI_C_SOURCE 199309L
#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
	#ifdef _POSIX_JOB_CONTROL
		cout<<"\njob control";
	#else
				cout<<"\nDoes not support job control";	

	#endif
	
	#ifdef _POSIX_SAVED_IDS
		cout<<"\nSupports saved set UID and GID";
	#else
		cout<<"\nno id";
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
		cout<<"\nchown restricted";
	#else
		cout<<"\nnochown";
	#endif
	
	#ifdef _POSIX_NO_TRUNC
		cout<<"\nno trunc";
	#else
		cout<<"\ndoes no trunc";
	#endif

	#ifdef _POSIX_VDISABLE
		cout<<"\njob control";
	#else
		cout<<"\nNo vi";
	#endif

}