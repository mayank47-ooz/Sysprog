#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
int fd[2]; // fd[0] = read end, fd[1] = write end
pipe(fd); // Create the pipe

    // First child: echo Hello
if (fork() == 0) {
dup2(fd[1], 1);   // Redirect stdout to pipe's write end
close(fd[0]);     // Close unused read end
close(fd[1]);     // Close original write end after dup2
execlp("echo", "echo", "Hello", NULL); // Run "echo Hello"
perror("execlp echo failed");
exit(1);
    }

    // Second child: wc -c
if (fork() == 0) {
dup2(fd[0], 0);   // Redirect stdin to pipe's read end
close(fd[1]);     // Close unused write end
close(fd[0]);     // Close original read end after dup2
execlp("wc", "wc", "-c", NULL); // Run "wc -c"
perror("execlp wc failed");
exit(1);
    }

    // Parent process
close(fd[0]); // Close both ends of the pipe
close(fd[1]);

    // Wait for both children
wait(NULL);
wait(NULL);

    return 0;
}

