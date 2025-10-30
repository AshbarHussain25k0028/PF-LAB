#include <stdio.h>

int main() {
    int board[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rotated[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            rotated[j][2-i] = board[i][j];
        }
    }

    printf("Original Game Board:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("\nRotated Game Board (90° Clockwise):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", rotated[i][j]);
        }
        printf("\n");
    }

    return 0;
}

