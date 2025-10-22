#include <stdio.h>
int main() {
    int n,i;
    printf("Enter number of readings: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter readings:\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    int max=arr[0],min=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    printf("Maximum = %d\nMinimum = %d\n",max,min);
    return 0;
}

