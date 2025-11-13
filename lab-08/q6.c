#include <stdio.h>
#include <string.h>

char* formatName(char *first, char *last);

int main() {
    char first[20], last[20];
    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);
    printf("Full Name: %s\n", formatName(first, last));
    return 0;
}

char* formatName(char *first, char *last) {
    static char full[50];
    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);
    return full;
}

