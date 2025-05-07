#include <stdio.h>

int main() {
    printf("Enter something: ");
    // No newline, no fflush
    char input[100];
    fgets(input, sizeof(input), stdin);

    printf("You typed: %s", input);
    return 0;
}

