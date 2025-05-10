#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Enter your name: ");
    fgets(name, 100, stdin);

    if (strcmp(name, "Alice") == 0) {
        printf("Welcome, Alice!\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}











