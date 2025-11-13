#include <stdio.h>

void updateValue(int x);
void updateReference(int *x);

int main() {
    int num = 80;
    printf("Before updateValue: %d\n", num);
    updateValue(num);
    printf("After updateValue: %d (no change)\n", num);
    printf("Before updateReference: %d\n", num);
    updateReference(&num);
    printf("After updateReference: %d (updated successfully)\n", num);
    return 0;
}

void updateValue(int x) {
    x = 85;
}

void updateReference(int *x) {
    *x = 85;
}

