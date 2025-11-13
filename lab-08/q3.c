#include <stdio.h>

void inputData(int arr[], int n);
void findRoads(int arr[], int n, int target, int *r1, int *r2);

int main() {
    int n, target, r1, r2;
    printf("Enter number of roads: ");
    scanf("%d", &n);
    int vehicles[n];
    inputData(vehicles, n);
    printf("Enter target vehicle count: ");
    scanf("%d", &target);
    findRoads(vehicles, n, target, &r1, &r2);
    printf("Road %d and Road %d have combined traffic equal to %d\n", r1 + 1, r2 + 1, target);
    return 0;
}

void inputData(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter vehicles on road %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void findRoads(int arr[], int n, int target, int *r1, int *r2) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                *r1 = i;
                *r2 = j;
                return;
            }
        }
    }
}

