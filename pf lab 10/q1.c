#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 200

int main() {
    char songs[MAX][LEN];
    int n = 0;
    FILE *f = fopen("playlist.txt","r");
    if(f){
        while(fgets(songs[n], LEN, f)){
            songs[n][strcspn(songs[n], "\n")] = 0;
            n++;
        }
        fclose(f);
    }

    while(1){
        char opt[LEN], temp[LEN];
        printf("Option (add/delete/update/search or -1): ");
        fgets(opt, LEN, stdin);
        opt[strcspn(opt,"\n")] = 0;

        if(strcmp(opt,"-1")==0) break;

        if(strcmp(opt,"add")==0){
            if(n<MAX){
                printf("Title: ");
                fgets(songs[n], LEN, stdin);
                songs[n][strcspn(songs[n],"\n")] = 0;
                n++;
            }
        }

        else if(strcmp(opt,"delete")==0){
            printf("Title: ");
            fgets(temp, LEN, stdin);
            temp[strcspn(temp,"\n")] = 0;
            int i,j;
            for(i=0;i<n;i++){
                if(strcmp(songs[i],temp)==0){
                    for(j=i;j<n-1;j++) strcpy(songs[j],songs[j+1]);
                    n--;
                    break;
                }
            }
        }

        else if(strcmp(opt,"update")==0){
            printf("Old title: ");
            fgets(temp, LEN, stdin);
            temp[strcspn(temp,"\n")] = 0;
            int i;
            for(i=0;i<n;i++){
                if(strcmp(songs[i],temp)==0){
                    printf("New title: ");
                    fgets(songs[i], LEN, stdin);
                    songs[i][strcspn(songs[i],"\n")] = 0;
                    break;
                }
            }
        }

        else if(strcmp(opt,"search")==0){
            printf("Title: ");
            fgets(temp, LEN, stdin);
            temp[strcspn(temp,"\n")] = 0;
            int i, found = 0;
            for(i=0;i<n;i++){
                if(strcmp(songs[i],temp)==0){
                    printf("Found\n");
                    found = 1;
                    break;
                }
            }
            if(!found) printf("Not found\n");
        }
    }

    int i,j;
    char t[LEN];
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(songs[i],songs[j])>0){
                strcpy(t,songs[i]);
                strcpy(songs[i],songs[j]);
                strcpy(songs[j],t);
            }
        }
    }

    printf("\nFinal Playlist:\n");
    for(i=0;i<n;i++) printf("%s\n",songs[i]);

    f = fopen("playlist.txt","w");
    for(i=0;i<n;i++) fprintf(f,"%s\n",songs[i]);
    fclose(f);

    return 0;
}

