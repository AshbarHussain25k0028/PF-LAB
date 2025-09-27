#include <stdio.h>
int main() {
    int age, movie;
    printf("enter your age: ");
    scanf("%d", &age);

    if (age < 12) {
        printf("ticket type: child\n");
        printf("select movie:\n1. action\n2. comedy\n3. horror\n");
        scanf("%d", &movie);
        switch (movie) {
            case 1: printf("child ticket + action movie booked\n"); break;
            case 2: printf("child ticket + comedy movie booked\n"); break;
            case 3: printf("child ticket + horror movie booked\n"); break;
            default: printf("invalid movie selection\n");
        }
    } else if (age <= 60) {
        printf("ticket type: adult\n");
        printf("select movie: 1. action  2. comedy  3. horror\n");
        scanf("%d", &movie);
        switch (movie) {
            case 1: printf("adult ticket + action movie booked\n"); break;
            case 2: printf("adult ticket + comedy movie booked\n"); break;
            case 3: printf("adult ticket + horror movie booked\n"); break;
            default: printf("invalid movie selection\n");
        }
    } else {
        printf("ticket type: senior citizen\n");
        printf("select movie:\n1. action\n2. comedy\n3. horror\n");
        scanf("%d", &movie);
        switch (movie) {
            case 1: printf("senior citizen ticket + action movie booked\n"); break;
            case 2: printf("senior citizen ticket + comedy movie booked\n"); break;
            case 3: printf("senior citizen ticket + horror movie booked\n"); break;
            default: printf("invalid movie selection\n");
        }
    }
    return 0;
}


