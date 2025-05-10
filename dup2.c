#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(file, 1);  // stdout now goes to the file

    printf("Hello, file!\n");  // This will go into output.txt
    close(file);
    return 0;
}

