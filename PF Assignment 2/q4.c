#include <stdio.h>
void push(int stack[], int *top, int size) {
    int num;
    if (*top == size - 1) {
        printf("overflow\n");
    } else {
        printf("enter value: ");
        scanf("%d", &num);
        (*top)++;
        stack[*top] = num;
    }
}
void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("underflow\n");
    } else {
        printf("popped: %d\n", stack[*top]);
        (*top)--;
    }
}
void peek(int stack[], int top) {
    if (top == -1)
        printf("empty\n");
    else
        printf("top: %d\n", stack[top]);
}
void display(int stack[], int top) {
    int i;
    if (top == -1)
        printf("empty\n");
    else {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int main() {
    int stack[100];
    int top = -1, size, choice;
    printf("enter stack size: ");
    scanf("%d", &size);
    do {
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        scanf("%d", &choice);
        if (choice == 1)
            push(stack, &top, size);
        else if (choice == 2)
            pop(stack, &top);
        else if (choice == 3)
            peek(stack, top);
        else if (choice == 4)
            display(stack, top);
    } while (choice != 5);
    return 0;
}

