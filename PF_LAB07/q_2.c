#include <stdio.h>
int main(){
    int n,i;
    printf("Enter number of readings: ");
    scanf("%d",&n);
    float arr[n],sum=0;
    printf("Enter readings:\n");
    for(i=0;i<n;i++){
        scanf("%f",&arr[i]);
        sum+=arr[i];
    }
    printf("Total = %.2f\nAverage = %.2f\n",sum,sum/n);
    return 0;
}

