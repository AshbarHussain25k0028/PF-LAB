#include <stdio.h>
#include <string.h>
void encodeMessage(char s[]) {
    int i, n, b;
    char t;
    n = strlen(s);
    for (i = 0; i < n / 2; i++) {
        t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
    for (i = 0; i < n; i++) {
        b = s[i];
        b ^= (1 << 1);
        b ^= (1 << 4);
        s[i] = b;
    }
}

void decodeMessage(char s[]) {
    int i, n, b;
    char t;
    n = strlen(s);
    for (i = 0; i < n; i++) {
        b = s[i];
        b ^= (1 << 1);
        b ^= (1 << 4);
        s[i] = b;
    }
    for (i = 0; i < n / 2; i++) {
        t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
}
int main() {
    int ch;
    char s[200];
    while (1) {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\n");
        scanf("%d", &ch);
        getchar();
        if (ch == 1) {
            printf("Enter message: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;
            encodeMessage(s);
            printf("Encoded: %s\n", s);
        } else if (ch == 2) {
            printf("Enter encoded message: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;
            decodeMessage(s);
            printf("Decoded: %s\n", s);
        } else if (ch == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

