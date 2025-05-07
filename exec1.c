#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

char *args[]={"ls","-l",NULL};

execvp(args[0],args);

perror("execvp");

exit(EXIT_FAILURE);

}
