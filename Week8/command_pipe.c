#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <stdlib.h> 
int main(){
int pfds[2];
char buf[80];
 
if(pipe(pfds)==-1){
perror("pipe failed");
exit(1);
}
 
if(!fork()){
close(pfds[0]);
dup(pfds[1]);
execlp("ls","ls","-l",NULL);
}
 
else{
printf("parent reading from pipe \n");
while(read(pfds[0],buf,80)>0){
printf("%s \n" ,buf);
}
}
}
