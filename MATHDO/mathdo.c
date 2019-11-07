#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int a,b,result;
  int pid,pid1,pid2,pid3;
 
  if(argc!=3){
    printf("Invalid args...\n");
      return -1;
 }

 a = atoi(argv[1]);
 b = atoi(argv[2]);

 pid=fork();
 if(pid == 0) {
   execlp("python3",":)","add.py",argv[1],argv[2],NULL);
   exit(0);
 }

else{
   pid1=fork();
   if(pid1 == 0){
    execlp("java",":)","subtraction.java",argv[1],argv[2],NULL);
    exit(0);
   }

else{
  pid2=fork();
  if(pid2 == 0){
    execlp("node",":)","multiplication.js",argv[1],argv[2],NULL);
    exit(0);
  }
else{
  pid3=fork();
  if(pid3 == 0){
    execlp("bash",":)","division.sh",argv[1],argv[2],NULL);
    exit(0);
  }
else{ 
  int rc_wait = waitpid(pid1,0,0);
  printf("parent: done.\n");
}
}
}
}
 return 0;
}
