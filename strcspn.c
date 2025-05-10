#include <stdio.h>
#include <string.h>

#define MAX_LINE 100

int main() {
char line[MAX_LINE];
printf("Enter your name: ");
if (fgets(line, MAX_LINE, stdin)) {
	line[strcspn(line, "\n")] = '\0';  // Remove newline
        printf("Hello, %s!\n", line);
}

    return 0;
}

