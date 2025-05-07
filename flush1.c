#include <stdio.h>

int main() {
    printf("Enter something: ");
    fflush(stdout);//force output
    char input[100];
    fgets(input, sizeof(input), stdin);

    printf("You typed: %s", input);
    return 0;
}

