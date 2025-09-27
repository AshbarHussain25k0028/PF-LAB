#include <stdio.h>

int main() {
    int num1, num2, num3, SecondLargest;
    
 
    printf("Enter 3 integer numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)) {
        SecondLargest = num1;
    } else if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)) {
        SecondLargest = num2;
    } else {
        SecondLargest = num3;
    }

    printf("The second largest is %d\n", SecondLargest);

    return 0;
}
