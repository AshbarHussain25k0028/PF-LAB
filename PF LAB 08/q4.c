#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int hall[rows][cols];
    int i, j, available = 0, max_empty = 0, row_with_max = 0;

    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        int empty_in_row = 0;
        for (j = 0; j < cols; j++) {
            hall[i][j] = rand() % 2;
            if (hall[i][j] == 0) {
                available++;
                empty_in_row++;
            }
        }
        if (empty_in_row > max_empty) {
            max_empty = empty_in_row;
            row_with_max = i;
        }
    }

    printf("Total Available Seats: %d\n", available);
    printf("Row with Most Empty Seats: Row %d (%d empty seats)\n", row_with_max+1, max_empty);

    printf("\nSeating Arrangement (0=Empty, 1=Occupied):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", hall[i][j]);
        }
        printf("\n");
    }

    return 0;
}

