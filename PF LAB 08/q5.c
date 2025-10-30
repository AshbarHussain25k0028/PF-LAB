#include <stdio.h>

int main() {
    int marks[5][4];
    int i, j;
    float avg[5];
    int high[4];

    printf("Enter marks for 5 students in 4 subjects:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        float sum = 0;
        for (j = 0; j < 4; j++) {
            sum += marks[i][j];
        }
        avg[i] = sum / 4.0;
    }

    for (j = 0; j < 4; j++) {
        high[j] = marks[0][j];
        for (i = 1; i < 5; i++) {
            if (marks[i][j] > high[j]) {
                high[j] = marks[i][j];
            }
        }
    }

    printf("Average marks of each student: [");
    for (i = 0; i < 5; i++) {
        printf("%.2f", avg[i]);
        if (i != 4) printf(", ");
    }
    printf("]\n");

    printf("Highest marks in each subject: [");
    for (j = 0; j < 4; j++) {
        printf("%d", high[j]);
        if (j != 3) printf(", ");
    }
    printf("]\n");
    return 0;
}

