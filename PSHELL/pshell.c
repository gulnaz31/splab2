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

	char hl[1000];
	char* m[100];

	m[0] = "/bin/bash";
	m[1] = "-c";
	m[3] = NULL;
	do {
		printf("$ Enter your command: ");
		fgets(hl, 1000, stdin);
		char *pch = strtok(hl, "\n");
		m[2] = hl;

		if(strcmp(pch, "exit") == 0){
		break;
		}
		if(strcmp(pch, "showjobs") == 0){
m[2] = "ps | awk '$4 != \"pshell\" && $4 != \"bash\" && $4 != \"awk\" && $4 != \"ps\" && $4 != \"CMD\"' | awk '{print NR\".\", \"[\"$1\"]\"}'";
		}		

		pid_t p = fork();
		if (p == 0){
			execvp(m[0], m);
		}

		waitpid(p, NULL,0);
	}while(1);

	return 0;

}

