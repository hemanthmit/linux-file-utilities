#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

int pid;
pid=fork();
if(pid < 0){
printf("\n Fork Failed \n");
exit(-1);
}
else if (pid == 0){
execlp("/bin/ls","ls", "-l", NULL);
}
else{
wait(NULL);
printf("\n child complete \n");
exit(0);	
}
}
