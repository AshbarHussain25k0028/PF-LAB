#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 200

char aff[MAX][LEN];
int count = 0;

void load() {
    FILE *f = fopen("affirm.txt", "r");
    int i = 0;
    if (!f) return;

    while (fgets(aff[count], LEN, f)) {
        aff[count][strcspn(aff[count], "\n")] = '\0';
        count++;
    }
    fclose(f);
}

void save() {
    FILE *f = fopen("affirm.txt", "w");
    int i;
    for (i = 0; i < count; i++) {
        fprintf(f, "%s\n", aff[i]);
    }
    fclose(f);
}

int wordCount(char *s){
    int c = 0;
    char temp[LEN];
    char *tok;

    strcpy(temp, s);
    tok = strtok(temp, " ");

    while (tok) {
        c++;
        tok = strtok(NULL, " ");
    }
    return c;
}

void add() {
    char temp[LEN];
    printf("Enter new affirmation: ");
    fgets(temp, LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if (wordCount(temp) > 7) {
        printf("Too long! Max 7 words.\n");
        return;
    }

    strcpy(aff[count], temp);
    count++;
}

void del() {
    int index;
    int j;

    printf("Enter index to delete (0-%d): ", count - 1);
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= count) {
        printf("Invalid\n");
        return;
    }

    for (j = index; j < count - 1; j++) {
        strcpy(aff[j], aff[j + 1]);
    }
    count--;
}

void update() {
    int index;
    char temp[LEN];

    printf("Enter index to update (0-%d): ", count - 1);
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= count) {
        printf("Invalid\n");
        return;
    }

    printf("Enter new affirmation: ");
    fgets(temp, LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if (wordCount(temp) > 7) {
        printf("Too long! Max 7 words.\n");
        return;
    }

    strcpy(aff[index], temp);
}

void search() {
    char key[LEN];
    int i;

    printf("Search phrase: ");
    fgets(key, LEN, stdin);
    key[strcspn(key, "\n")] = '\0';

    for (i = 0; i < count; i++) {
        if (strstr(aff[i], key)) {
            printf("%d: %s\n", i, aff[i]);
        }
    }
}

int main() {
    int ch;
    int i;

    load();

    while (1) {
        printf("\n1.Add  2.Delete  3.Update  4.Search  5.List  6.Exit\nChoice: ");
        scanf("%d", &ch);
        getchar();

        if (ch == 1) add();
        else if (ch == 2) del();
        else if (ch == 3) update();
        else if (ch == 4) search();
        else if (ch == 5) {
            for (i = 0; i < count; i++) {
                printf("%d: %s\n", i, aff[i]);
            }
        }
        else if (ch == 6) break;
    }

    save();
    return 0;
}

