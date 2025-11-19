#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 200

int countWords(char *s) {
    int i, c = 0;
    for(i=0; s[i]; i++) if(s[i] == ' ') c++;
    return c + 1;
}

void loadTags(char tags[][LEN], int *n) {
    FILE *f = fopen("tags.txt","r");
    if(!f) return;
    while(fgets(tags[*n], LEN, f)) {
        tags[*n][strcspn(tags[*n], "\n")] = 0;
        (*n)++;
    }
    fclose(f);
}

void saveTags(char tags[][LEN], int n) {
    FILE *f = fopen("tags.txt","w");
    int i;
    for(i=0;i<n;i++) fprintf(f, "%s\n", tags[i]);
    fclose(f);
}

void displayTags(char tags[][LEN], int n) {
    int i;
    for(i=0;i<n;i++) printf("%s\n", tags[i]);
}

void addTag(char tags[][LEN], int *n) {
    if(*n >= MAX) return;
    char temp[LEN];
    printf("Enter new tag: ");
    fgets(temp, LEN, stdin);
    temp[strcspn(temp,"\n")] = 0;

    if(countWords(temp) >= 5 && countWords(temp) <= 7) {
        strcpy(tags[*n], temp);
        (*n)++;
    } else {
        printf("Tag must be 5–7 words.\n");
    }
}

void deleteTag(char tags[][LEN], int *n) {
    char temp[LEN];
    printf("Tag to delete: ");
    fgets(temp, LEN, stdin);
    temp[strcspn(temp,"\n")] = 0;

    int i, j;
    for(i=0;i<*n;i++) {
        if(strcmp(tags[i], temp) == 0) {
            for(j=i;j<*n-1;j++) strcpy(tags[j], tags[j+1]);
            (*n)--;
            break;
        }
    }
}

void updateTag(char tags[][LEN], int n) {
    char old[LEN], new[LEN];
    printf("Tag to update: ");
    fgets(old, LEN, stdin);
    old[strcspn(old,"\n")] = 0;

    int i;
    for(i=0;i<n;i++) {
        if(strcmp(tags[i], old) == 0) {
            printf("Enter new tag: ");
            fgets(new, LEN, stdin);
            new[strcspn(new,"\n")] = 0;

            if(countWords(new) >= 5 && countWords(new) <= 7) {
                strcpy(tags[i], new);
            } else {
                printf("Tag must be 5–7 words.\n");
            }
            break;
        }
    }
}

void searchTag(char tags[][LEN], int n) {
    char key[LEN];
    printf("Search text: ");
    fgets(key, LEN, stdin);
    key[strcspn(key,"\n")] = 0;

    int i, found = 0;
    for(i=0;i<n;i++) {
        if(strstr(tags[i], key)) {
            printf("%s\n", tags[i]);
            found = 1;
        }
    }
    if(!found) printf("No matches found.\n");
}

int main() {
    char tags[MAX][LEN];
    int n = 0;

    loadTags(tags, &n);

    while(1) {
        char opt[LEN];
        printf("\nOptions: add / delete / update / search / show / -1: ");
        fgets(opt, LEN, stdin);
        opt[strcspn(opt,"\n")] = 0;

        if(strcmp(opt, "-1") == 0) break;
        else if(strcmp(opt, "add") == 0) addTag(tags, &n);
        else if(strcmp(opt, "delete") == 0) deleteTag(tags, &n);
        else if(strcmp(opt, "update") == 0) updateTag(tags, n);
        else if(strcmp(opt, "search") == 0) searchTag(tags, n);
        else if(strcmp(opt, "show") == 0) displayTags(tags, n);
    }

    saveTags(tags, n);

    return 0;
}

