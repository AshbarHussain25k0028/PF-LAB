#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 200

int words(char s[]) {
    int c=0,i;
    for(i=0;s[i];i++) if(s[i]==' ') c++;
    return c+1;
}

int main() {
    char a[MAX][LEN];
    int n=0;

    FILE *f = fopen("affirm.txt","r");
    if(f){
        while(fgets(a[n],LEN,f)){
            a[n][strcspn(a[n],"\n")] = 0;
            n++;
        }
        fclose(f);
    }

    while(1){
        char opt[LEN], t[LEN];
        printf("Option (add/delete/update/search or -1): ");
        fgets(opt,LEN,stdin);
        opt[strcspn(opt,"\n")] = 0;

        if(strcmp(opt,"-1")==0) break;

        if(strcmp(opt,"add")==0 && n<MAX){
            printf("Enter affirmation: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")] = 0;
            if(words(t)<=7){
                strcpy(a[n],t);
                n++;
            } else {
                printf("Too long\n");
            }
        }

        else if(strcmp(opt,"delete")==0){
            printf("Delete: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")] = 0;
            int i,j;
            for(i=0;i<n;i++){
                if(strcmp(a[i],t)==0){
                    for(j=i;j<n-1;j++) strcpy(a[j],a[j+1]);
                    n--;
                    break;
                }
            }
        }

        else if(strcmp(opt,"update")==0){
            printf("Old: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")] = 0;
            int i;
            for(i=0;i<n;i++){
                if(strcmp(a[i],t)==0){
                    printf("New: ");
                    fgets(a[i],LEN,stdin);
                    a[i][strcspn(a[i],"\n")] = 0;
                    if(words(a[i])>7) strcpy(a[i],t);
                    break;
                }
            }
        }

        else if(strcmp(opt,"search")==0){
            printf("Phrase: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")] = 0;
            int i,found=0;
            for(i=0;i<n;i++){
                if(strstr(a[i],t)){
                    printf("%s\n",a[i]);
                    found=1;
                }
            }
            if(!found) printf("Not found\n");
        }
    }

    FILE *fw = fopen("affirm.txt","w");
    int i;
    for(i=0;i<n;i++) fprintf(fw,"%s\n",a[i]);
    fclose(fw);

    return 0;
}

