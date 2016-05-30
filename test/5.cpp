#include <iostream>
int main(int argc,char *argv[],char *env[]){
	for(int i=1;env[i]!=NULL;i++)
		std::cout<<env[i]<<std::endl;
}