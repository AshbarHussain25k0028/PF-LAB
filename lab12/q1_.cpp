#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	printf("enter number of categories \n");
	scanf("%d",&num);
	int *stock = (int*) malloc(num*sizeof(int));
	 printf("Enter stock quantity for each category:\n");
    for (int i = 0; i < num; i++) {
        printf("Category %d: ", i);
        scanf("%d", &stock[i]);
    }

    int total = 0;
    for (int i = 0; i < num; i++) {
        total += stock[i];
    }

    float average = (float)total / num;


    int minIndex = 0;
    for (int i = 1; i < num; i++) {
        if (stock[i] < stock[minIndex]) {
            minIndex = i;
        }
    }


    printf("\nTotal stock: %d\n", total);
    printf("Average stock per category: %.2f\n", average);
    printf("Category with lowest stock: %d (stock = %d)\n", minIndex, stock[minIndex]);

   
    int updateIndex, newStock;
    printf("\nEnter category index to update stock: ");
    scanf("%d", &updateIndex);

    if (updateIndex >= 0 && updateIndex < num) {
        printf("Enter new stock for category %d: ", updateIndex);
        scanf("%d", &newStock);
        stock[updateIndex] = newStock;

        printf("\nUpdated stock array:\n");
        for (int i = 0; i < num; i++) {
            printf("Category %d: %d\n", i, stock[i]);
        }
    } else {
        printf("Invalid category index!\n");
    }

}
