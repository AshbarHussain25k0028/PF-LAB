#include <stdio.h>
int main() {
    int a, b;
    int temp; 
    printf("Enter the first integer a ");
    scanf("%d", &a);
    printf("Enter the second integer b ");
    scanf("%d", &b);
    temp = a; 
    a = b;    
    b = temp; 
    printf("After swapping values: a = %d, b = %d\n", a, b);
}

