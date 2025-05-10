#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file < 0) {
        perror("open");
        return 1;
    }

    dup2(file, 1);  // stdout now goes to the file

    printf("Hello, file!\n");  // Will append this line each time
    close(file);
    return 0;
}

