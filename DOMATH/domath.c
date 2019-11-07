#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wait.h>

int main(int argc, char **argv){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	pid_t p1 = fork();
	if(p1==0){
		printf("child1: %d+%d=%d\n", a, b, a+b);
	}
	waitpid(p1, 0, 0);
	pid_t p2 = fork();
	if(p2==0 && p1>0){
		printf("child2: %d-%d=%d\n", a, b, a-b);
	}
	waitpid(p2, 0, 0);
	pid_t p3 = fork();
	if(p2>0 && p3==0 && p1>0){
		printf("child3: %d*%d=%d\n", a, b, a*b);
	}
	waitpid(p3, 0, 0);
	pid_t p4 = fork();
	if(p4==0 && p3>0 && p2>0 && p1>0){
		printf("child4: %d/%d=%d\n", a, b, a/b);
	}
	waitpid(p4, 0, 0);
	if(p1>0 && p2>0 && p3>0 && p4>0){
		printf("parent: done.");
	}
}
