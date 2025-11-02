#include <stdio.h>
#include <stdlib.h>
void updateStatus(int sectors[3][3], int row, int col, int bitPos, int setFlag) {
    if (setFlag)
        sectors[row][col] = sectors[row][col] | (1 << bitPos);
    else
        sectors[row][col] = sectors[row][col] & ~(1 << bitPos);
}
void showStatus(int sectors[3][3], int row, int col) {
    int status;
    status = sectors[row][col];
    printf("Sector (%d,%d):\n", row, col);
    printf("Power: %s\n", (status & (1 << 0)) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & (1 << 1)) ? "YES" : "NO");
    printf("Maintenance: %s\n", (status & (1 << 2)) ? "REQUIRED" : "NO");
}
void runCheck(int sectors[3][3]) {
    int i, j;
    int overloadCount = 0;
    int maintenanceCount = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (sectors[i][j] & (1 << 1))
                overloadCount++;
            if (sectors[i][j] & (1 << 2))
                maintenanceCount++;
        }
    }
    printf("Overloaded Sectors: %d\n", overloadCount);
    printf("Maintenance Required: %d\n", maintenanceCount);
}
int main() {
    int sectors[3][3] = {0};
    int option, row, col, bitPos, setFlag;
    do {
        printf("\n1. Update Sector\n2. Show Sector Status\n3. Run System Check\n4. Exit\nEnter choice: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Enter row and column: ");
            scanf("%d %d", &row, &col);
            printf("Enter bit (0=Power, 1=Overload, 2=Maintenance): ");
            scanf("%d", &bitPos);
            printf("Set(1) or Clear(0): ");
            scanf("%d", &setFlag);
            updateStatus(sectors, row, col, bitPos, setFlag);
        } else if (option == 2) {
            printf("Enter row and column: ");
            scanf("%d %d", &row, &col);
            showStatus(sectors, row, col);
        } else if (option == 3) {
            runCheck(sectors);
        }
    } while (option != 4);
    return 0;
}

