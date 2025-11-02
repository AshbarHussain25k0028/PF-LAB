#include <stdio.h>
#include <string.h>

void encodeText(char msg[]) {
    int i, len, tempChar;
    char temp;
    len = strlen(msg);
    for (i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }
    for (i = 0; i < len; i++) {
        tempChar = msg[i];
        tempChar ^= 2;
        tempChar ^= 16;
        msg[i] = tempChar;
    }
}

void decodeText(char msg[]) {
    int i, len, tempChar;
    char temp;
    len = strlen(msg);
    for (i = 0; i < len; i++) {
        tempChar = msg[i];
        tempChar ^= 2;
        tempChar ^= 16;
        msg[i] = tempChar;
    }
    for (i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }
}

int main() {
    int choice;
    char text[200];
    while (1) {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\n");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            printf("Enter message: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0;
            encodeText(text);
            printf("Encoded: %s\n", text);
        } 
        else if (choice == 2) {
            printf("Enter encoded message: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0;
            decodeText(text);
            printf("Decoded: %s\n", text);
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

