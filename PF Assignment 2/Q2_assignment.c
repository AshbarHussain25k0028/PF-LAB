#include <stdio.h>
#include <string.h>
#define inventory_limit 4
void contactInfo(char Name[][25], int CNIC[]);
void Inventory(int ProductCode[], int Qty[], int Price[], int size);
void Update(int ProductCode[], int Qty[], int size);
void Cart(int ProductCode[], int Qty[], int Price[], int size, int *customer_qty, int *customer_codes, int *cart_size);
void Bill(int *customer_qty, int *customer_codes, int *cart_size, int *Qty_master, int *Price_master, int *ProductCode_master, int master_size);
void Invoice(int *customer_qty, int *customer_codes, int *cart_size, int *Qty_master, int *Price_master, int *ProductCode_master, int master_size, char Name[][25], int CNIC[]);

int main() {
    int ProductCode[inventory_limit] = {1, 2, 3, 4};
    int Qty[inventory_limit] = {50, 10, 20, 8};
    int Price[inventory_limit] = {100, 200, 300, 150};
    char Name[1][25];
    int CNIC[1];
    int customer_codes[100];
    int customer_qty[100];
    int cart_size = 0;
    int choice;

    do {
        printf("\n1. Customer Info\n2. Show Inventory\n3. Update Inventory\n4. Add to Cart\n5. Bill\n6. Invoice\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: contactInfo(Name, CNIC); break;
            case 2: Inventory(ProductCode, Qty, Price, inventory_limit); break;
            case 3: Update(ProductCode, Qty, inventory_limit); break;
            case 4: Cart(ProductCode, Qty, Price, inventory_limit, customer_qty, customer_codes, &cart_size); break;
            case 5: Bill(customer_qty, customer_codes, &cart_size, Qty, Price, ProductCode, inventory_limit); break;
            case 6: Invoice(customer_qty, customer_codes, &cart_size, Qty, Price, ProductCode, inventory_limit, Name, CNIC); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}

void contactInfo(char Name[][25], int CNIC[]) {
    printf("Enter Name: ");
    scanf("%s", Name[0]);
    printf("Enter CNIC: ");
    scanf("%d", &CNIC[0]);
}

void Inventory(int ProductCode[], int Qty[], int Price[], int size) {
    int i;
    printf("\nCode\tQty\tPrice\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", ProductCode[i], Qty[i], Price[i]);
    }
}

void Update(int ProductCode[], int Qty[], int size) {
    int code, new_qty, found, i;
    found = 0;
    printf("Enter code: ");
    scanf("%d", &code);
    printf("Enter new qty: ");
    scanf("%d", &new_qty);
    for (i = 0; i < size; i++) {
        if (ProductCode[i] == code) {
            Qty[i] = new_qty;
            found = 1;
            printf("Updated.\n");
            break;
        }
    }
    if (!found) printf("Not found.\n");
}

void Cart(int ProductCode[], int Qty[], int Price[], int size, int *customer_qty, int *customer_codes, int *cart_size) {
    int code, qty, found, i;
    found = 0;
    printf("Enter product code: ");
    scanf("%d", &code);
    printf("Enter qty: ");
    scanf("%d", &qty);
    for (i = 0; i < size; i++) {
        if (ProductCode[i] == code) {
            found = 1;
            if (Qty[i] >= qty) {
                Qty[i] -= qty;
                customer_codes[*cart_size] = code;
                customer_qty[*cart_size] = qty;
                (*cart_size)++;
                printf("Added to cart.\n");
            } else printf("Not enough stock.\n");
            break;
        }
    }
    if (!found) printf("Code not found.\n");
}

void Bill(int *customer_qty, int *customer_codes, int *cart_size, int *Qty_master, int *Price_master, int *ProductCode_master, int master_size) {
    double total = 0, discount = 0, final_total;
    char promo[25];
    int i, j, code, qty, price;
    if (*cart_size == 0) {
        printf("Cart empty.\n");
        return;
    }
    for (i = 0; i < *cart_size; i++) {
        code = customer_codes[i];
        qty = customer_qty[i];
        price = 0;
        for (j = 0; j < master_size; j++) {
            if (ProductCode_master[j] == code) price = Price_master[j];
        }
        total += qty * price;
        printf("Code %d Qty %d Price %d\n", code, qty, price);
    }
    printf("Total: %.2f\nEnter promo (or NO): ", total);
    scanf("%s", promo);
    if (strcmp(promo, "Eid2025") == 0) discount = total * 0.25;
    final_total = total - discount;
    printf("Final: %.2f\n", final_total);
}

void Invoice(int *customer_qty, int *customer_codes, int *cart_size, int *Qty_master, int *Price_master, int *ProductCode_master, int master_size, char Name[][25], int CNIC[]) {
    double total = 0, discount = 0, final_total;
    char promo[25];
    int i, j, code, qty, price;
    if (*cart_size == 0) {
        printf("Cart empty.\n");
        return;
    }
    printf("\nInvoice\nName: %s\nCNIC: %d\n", Name[0], CNIC[0]);
    for (i = 0; i < *cart_size; i++) {
        code = customer_codes[i];
        qty = customer_qty[i];
        price = 0;
        for (j = 0; j < master_size; j++) {
            if (ProductCode_master[j] == code) price = Price_master[j];
        }
        total += qty * price;
        printf("Code %d Qty %d Price %d\n", code, qty, price);
    }
    printf("Total: %.2f\nPromo (or NO): ", total);
    scanf("%s", promo);
    if (strcmp(promo, "Eid2025") == 0) discount = total * 0.25;
    final_total = total - discount;
    printf("Final: %.2f\n", final_total);
}

