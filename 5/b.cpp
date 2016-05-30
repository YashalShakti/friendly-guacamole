#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[]) {
	switch(argc){
		case 3:
			cout<<"Hardlink created\n";
			return link(argv[1],argv[2]);
		case 4:
			if(!strcmp(argv[1],"-s")){
			cout<<"Symlink created\n";
			return symlink(argv[2],argv[3]);
			}
			cout<<"Use -s for symlink\n";
			return -1;
	}
	cout<<"Enter args\n";
	return 0;
}