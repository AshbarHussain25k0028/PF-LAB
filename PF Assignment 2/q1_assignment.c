#include <stdio.h>
#include <string.h>

void AddBook(int isbns[], int quantities[], char titles[][50], float prices[], int *count, int max);
void ProcessSale(int isbns[], int quantities[], int count);
void LowStock(int isbns[], int quantities[], char titles[][50], float prices[], int count);

int main() {
    int isbns[100], quantities[100];
    char titles[100][50];
    float prices[100];
    int option, count = 0;
    int max = 100;

    do {
        printf("\n====== Liberty Books Inventory System ======\n");
        printf("1. Add a Book\n");
        printf("2. Process a Sale\n");
        printf("3. Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                AddBook(isbns, quantities, titles, prices, &count, max);
                break;
            case 2:
                ProcessSale(isbns, quantities, count);
                break;
            case 3:
                LowStock(isbns, quantities, titles, prices, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid Input.\n");
        }
    } while (option != 4);

    return 0;
}

void AddBook(int isbns[], int quantities[], char titles[][50], float prices[], int *count, int max) {
    if (*count >= max) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    int isbn,i, duplicate = 0;
    char input[50];

    while (1) {
        printf("Enter 13-digit book ISBN: ");
        scanf("%s", input);

        int i,valid = 1, length = 0;

        for ( i = 0; input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
            length++;
        }

        if (!valid || length != 13) {
            printf("Invalid ISBN! Must be a 13-digit integer.\n");
            continue;
        }

        sscanf(input, "%d", &isbn);
        break;
    }
    for ( i = 0; i < *count; i++) {
        if (isbns[i] == isbn) {
            printf("Error: ISBN already exists!\n");
            duplicate = 1;
            break;
        }
    }
    if (duplicate) return;
    isbns[*count] = isbn;
    printf("Enter book title: ");
    scanf(" %[^\n]", titles[*count]);
    printf("Enter book price: ");
    scanf("%f", &prices[*count]);
    printf("Enter book quantity: ");
    scanf("%d", &quantities[*count]);
    (*count)++;
    printf("Book added successfully!\n");
}
void ProcessSale(int isbns[], int quantities[], int count) {
    int i,isbn, copies, found = 0;

    if (count == 0) {
        printf("No books in inventory.\n");
        return;
    }
    printf("Enter ISBN of the book sold: ");
    scanf("%d", &isbn);

    for ( i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &copies);
            if (copies > quantities[i]) {
                printf("Not enough stock \n");
            } else {
                quantities[i] -= copies;
                printf("Sale processed \n");
                printf("Remaining quantity: %d\n", quantities[i]);
                if (quantities[i] == 0) {
                    printf("This book is out of stock \n");
                }
            }
            break;
        }
    }
    if (found!=0) {
        printf("ISBN not found \n");
    }
}
void LowStock(int isbns[], int quantities[], char titles[][50], float prices[], int count) {
    int i,found = 0;

    if (count == 0) {
        printf("No books in inventory \n");
        return;
    }
    printf("\n====== Low Stock Report======\n");
    for ( i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d\n", isbns[i]);
            printf("Title: %s\n", titles[i]);
            printf("Price: %.2f\n", prices[i]);
            printf("Quantity: %d\n\n", quantities[i]);
            found = 1;
        }
    }
    if (found!=0) {
        printf("All books are in stock \n");
    }
}

