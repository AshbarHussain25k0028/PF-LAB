#include <stdio.h>
int main() {
    int category, option;
    printf("Select a category:\n");
    printf("1. Fast Food\n");
    printf("2. Drinks\n");
    printf("Enter your choice: ");
    scanf("%d", &category);
    switch (category) {
        case 1:
            printf("Choose an item:\n");
            printf("1. Spring Rolls\n");
            printf("2. Pizza\n");
            printf("3. Burger\n");
            printf("Enter your choice: ");
            scanf("%d", &option);
            switch (option) {
                case 1: printf("You ordered a Spring Roll.\n"); 
				break;
                case 2: printf("You ordered a Pizza.\n"); 
				break;
                case 3: printf("You ordered a Burger.\n"); 
				break;
                default: printf("Invalid item choice in Fast Food.\n");
            }
            break;
        case 2:
            printf("Choose an item:\n");
            printf("1. Lemonade\n");
            printf("2. Soda\n");
            printf("3. Water\n");
            printf("Enter your choice: ");
            scanf("%d", &option);
            switch (option) {
                case 1: printf("You ordered a Lemonade.\n"); 
				break;
                case 2: printf("You ordered Soda.\n"); 
				break;
                case 3: printf("You ordered Water.\n"); 
				break;
                default: printf("Invalid input.\n");
            }
            break;
        default: printf("Invalid input.\n");
    }
    return 0;
}
