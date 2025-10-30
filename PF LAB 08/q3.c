#include <stdio.h>
#include <ctype.h>

int main() {
    char words[3][10] = {"Hello", "WORLD", "ASHBAR"};
    int i, j, count = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; words[i][j] != '\0'; j++) {
            char ch = toupper(words[i][j]);
            if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
                count++;
            }
        }
    }
    printf("Total vowels: %d\n", count);
    return 0;
}

