#include <string.h>
#include <stdio.h>
char tokens[3][10];

void generate(int flag){
	printf("if %s goto 101\n",tokens[1]);
	printf("goto 102\n");
	printf("101: %s\n", tokens[3]);
	if(flag){
		printf("goto 103\n");
		printf("102: %s\n",tokens[5]);
		printf("103: end\n");
	}else{
		printf("102: end\n");
	}
}

int main(){
	int flag = 0;
	char sentence[100];
	char *token;
	int i=0;
	printf("Enter the sentence\n");
	gets(sentence);
	token = strtok(sentence," ");
	flag=0;
	while(token != NULL){
		strcpy(tokens[i++],token);
		if (strcmp(token,"else")==0){
			flag=1;
		}
		token = strtok(NULL," ");

	}
	generate(flag);
}
// if (a<b) then (s=a)