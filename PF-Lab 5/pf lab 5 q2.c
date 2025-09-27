#include <stdio.h>
int main(){
	int units;
	float bill;
	printf("enter number of units");
	scanf("%d",&units);
	
	if (units<=100){
		bill = units*5;
	}
	else{
		if(units<=200){
			bill = (100*5)+(units-100)*7;
		}
		else{
			if(units<=300){
				bill = (100*5)+(100*7)+(units-200)*10;
			}
			else{
				bill = (100*5)+(100*7)+(100*10)+(units-300)*15;
			}
		}
	}
	printf("total bill is = Rs %.2f\n",bill);
}
