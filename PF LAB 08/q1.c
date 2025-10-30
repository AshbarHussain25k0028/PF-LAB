#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int image[8][8], brightImage[8][8];
    int i, j;
    srand(time(NULL));

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            image[i][j] = rand() % 256;
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            brightImage[i][j] = image[i][j] + 20;
            if (brightImage[i][j] > 255) brightImage[i][j] = 255;
        }
    }

    printf("Original Image:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\nBrightened Image:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%3d ", brightImage[i][j]);
        }
        printf("\n");
    }
    return 0;
}

