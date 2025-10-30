#include <stdio.h>

int main() {
    int inventory[2][3][4];
    int section_total[2] = {0, 0};
    int shelf_totals[2][3] = {0};
    int i, j, k;

    printf("Enter item quantities:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                scanf("%d", &inventory[i][j][k]);
                section_total[i] += inventory[i][j][k];
                shelf_totals[i][j] += inventory[i][j][k];
            }
        }
    }

    printf("Total items in each section:\n");
    for (i = 0; i < 2; i++) {
        printf("Section %d: %d\n", i + 1, section_total[i]);
    }

    int max_total = 0, max_section = 0, max_shelf = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            if (shelf_totals[i][j] > max_total) {
                max_total = shelf_totals[i][j];
                max_section = i;
                max_shelf = j;
            }
        }
    }
    printf("Shelf with the highest total quantity: Section %d, Shelf %d (%d items)\n", max_section + 1, max_shelf + 1, max_total);
    return 0;
}

