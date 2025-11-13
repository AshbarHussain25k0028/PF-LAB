#include <stdio.h>

void inputData(int arr[], int n);
float averagePatients(int arr[], int n);
int busiestDay(int arr[], int n);
int slowestDay(int arr[], int n);

int main() {
    int patients[7];
    inputData(patients, 7);
    float avg = averagePatients(patients, 7);
    int maxDay = busiestDay(patients, 7);
    int minDay = slowestDay(patients, 7);
    printf("Average Patients per Day: %.2f\n", avg);
    printf("Busiest Day: Day %d (%d patients)\n", maxDay + 1, patients[maxDay]);
    printf("Slowest Day: Day %d (%d patients)\n", minDay + 1, patients[minDay]);
    return 0;
}

void inputData(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter patients for day %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

float averagePatients(int arr[], int n) {
    int i, sum = 0;
    for(i = 0; i < n; i++) sum += arr[i];
    return (float)sum / n;
}

int busiestDay(int arr[], int n) {
    int i, max = arr[0], day = 0;
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            day = i;
        }
    }
    return day;
}

int slowestDay(int arr[], int n) {
    int i, min = arr[0], day = 0;
    for(i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            day = i;
        }
    }
    return day;
}

