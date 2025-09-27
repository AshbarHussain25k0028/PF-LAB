#include <stdio.h>
int main(){
	int choice,action;
	printf("Library management system\n");
	printf("1.Manage books\n");
	printf("2.Manage magazines\n");
	printf("enter your choice");
	scanf("%d",&choice);
	if(choice==1 ||choice==2){
		printf("1. issue, 2.Return\n");
		scanf("%d",&action);
		switch(action){
			case 1:
				if(choice==1){
				printf("you have issued a book\n");
			}
				else{
					printf("you have issued a magazine\n");
				}
				break;
			case 2:
				if(choice==1){
					printf("you have returned a book\n ");
				}
				else{
					printf("you have returned a magazine\n");
				}
				break;
		default:
			printf("invalid action\n");
				
		}
	}
	else{
		printf("invalid choice\n");
	}
}
