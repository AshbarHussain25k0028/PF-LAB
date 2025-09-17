#include <stdio.h>
int main() {
    int IntegerValue;
    printf("Enter an integer between 65 and 90: ");
    scanf("%d", &IntegerValue);
    if (IntegerValue >= 65 && IntegerValue <= 90) {
        printf("%d = %c", IntegerValue, (char)IntegerValue);
    } else {
        printf("Error: the input value is not in the given range");
    }
}

