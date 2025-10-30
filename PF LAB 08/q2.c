#include <stdio.h>

int main() {
    char names[5][21];
    int i;

    printf("Enter names of 5 students:\n");
    for (i = 0; i < 5; i++) {
        scanf("%20s", names[i]);
    }

    printf("\nStudent Names:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}

