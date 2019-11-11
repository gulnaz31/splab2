#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	char hl[1000]; //hello#world#of#linux
	char* m[100]; // 0 1 2 3

	m[0] = "/bin/bash";
	m[1] = "-c";
	m[3] = NULL;
	do {
		printf("$ Enter your command: ");
		fgets(hl, 1000, stdin);
		char *pch = strtok(hla, "\n");
		m[2] = hl;

		if(strcmp(pch, "exit") == 0){
		break;
		}

		pid_t p = fork();
		if (p == 0){
			execvp(m[0], m);
		}

		waitpid(p, NULL,0);
	}
	while(1);

	return 0;

}
