#include <stdio.h>
#include <string.h>

struct Book {
    int bookID;
    int popularityScore;
    int lastAccessTime;
};

int main() {
    int capacity, numberOfOperations;
    printf("Enter shelf capacity and number of operations: ");
    scanf("%d %d", &capacity, &numberOfOperations);

    struct Book shelf[1000];
    int currentSize = 0;
    int timeCounter = 1;

    int i;
    int leastIndex;
    int found;

    while (numberOfOperations--) {
        char operation[10];
        printf("Enter operation (ADD or ACCESS): ");
        scanf("%s", operation);

        if (strcmp(operation, "ADD") == 0) {
            int id, score;
            printf("Enter book ID and popularity score: ");
            scanf("%d %d", &id, &score);

            found = -1;
            for (i = 0; i < currentSize; i++) {
                if (shelf[i].bookID == id) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                shelf[found].popularityScore = score;
                shelf[found].lastAccessTime = timeCounter++;
            } else {
                if (currentSize == capacity) {
                    leastIndex = 0;
                    for (i = 1; i < currentSize; i++) {
                        if (shelf[i].lastAccessTime < shelf[leastIndex].lastAccessTime) {
                            leastIndex = i;
                        }
                    }
                    for (i = leastIndex; i < currentSize - 1; i++) {
                        shelf[i] = shelf[i + 1];
                    }
                    currentSize--;
                }
                shelf[currentSize].bookID = id;
                shelf[currentSize].popularityScore = score;
                shelf[currentSize].lastAccessTime = timeCounter++;
                currentSize++;
            }
        }

        else if (strcmp(operation, "ACCESS") == 0) {
            int id;
            printf("Enter book ID to access: ");
            scanf("%d", &id);

            found = -1;
            for (i = 0; i < currentSize; i++) {
                if (shelf[i].bookID == id) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", shelf[found].popularityScore);
                shelf[found].lastAccessTime = timeCounter++;
            }
        }
    }

    return 0;
}

