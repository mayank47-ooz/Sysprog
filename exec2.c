#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
pid_t pid;
int status;

pid=fork();
if(pid<0){

perror("fork");
exit(EXIT_FAILURE);
}

else if(pid==0){

char *args[]={"ls","-l",NULL};
execvp(args[0],args);
perror("execvp");
exit(EXIT_FAILURE);
}


else{
waitpid(pid,&status,0);
printf("child process finished with status %d\n",WEXITSTATUS(status));
}

return 0;
}
