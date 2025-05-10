#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
char line[] = "ls -l /home";
char *token = strtok(line, " ");

while (token != NULL) {
    printf("Token: %s\n", token);
    token = strtok(NULL, " ");  // Get the next token
}
}
