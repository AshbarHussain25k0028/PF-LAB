#include <stdio.h>
#include <string.h>

#define MAX 50
#define LEN 200

int wordcount(char s[]) {
    int c=0,i;
    for(i=0;s[i];i++) if(s[i]==' ') c++;
    return c+1;
}

int main() {
    char lvl[MAX][LEN];
    int n=0;
    FILE *f = fopen("levels.txt","r");
    if(f){
        while(fgets(lvl[n],LEN,f)){
            lvl[n][strcspn(lvl[n],"\n")]=0;
            n++;
        }
        fclose(f);
    }

    while(1){
        char opt[LEN], t[LEN];
        printf("Option (add/search/update/delete or -1): ");
        fgets(opt,LEN,stdin);
        opt[strcspn(opt,"\n")]=0;

        if(strcmp(opt,"-1")==0) break;

        if(strcmp(opt,"add")==0 && n<MAX){
            printf("Enter level: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")]=0;
            if(wordcount(t)<=7){
                strcpy(lvl[n],t);
                n++;
            }
        }

        else if(strcmp(opt,"search")==0){
            printf("Enter text: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")]=0;
            int i,found=0;
            for(i=0;i<n;i++){
                if(strstr(lvl[i],t)){
                    printf("Found: %s\n",lvl[i]);
                    found=1;
                }
            }
            if(!found) printf("Not found\n");
        }

        else if(strcmp(opt,"update")==0){
            printf("Old: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")]=0;
            int i;
            for(i=0;i<n;i++){
                if(strcmp(lvl[i],t)==0){
                    printf("New: ");
                    fgets(lvl[i],LEN,stdin);
                    lvl[i][strcspn(lvl[i],"\n")]=0;
                    if(wordcount(lvl[i])>7) strcpy(lvl[i],t);
                    break;
                }
            }
        }

        else if(strcmp(opt,"delete")==0){
            printf("Delete: ");
            fgets(t,LEN,stdin);
            t[strcspn(t,"\n")]=0;
            int i,j;
            for(i=0;i<n;i++){
                if(strcmp(lvl[i],t)==0){
                    for(j=i;j<n-1;j++) strcpy(lvl[j],lvl[j+1]);
                    n--;
                    break;
                }
            }
        }
    }

    int i,j;
    char tmp[LEN];
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(lvl[i],lvl[j])>0){
                strcpy(tmp,lvl[i]);
                strcpy(lvl[i],lvl[j]);
                strcpy(lvl[j],tmp);
            }
        }
    }

    f = fopen("levels.txt","w");
    for(i=0;i<n;i++) fprintf(f,"%s\n",lvl[i]);
    fclose(f);

    return 0;
}

