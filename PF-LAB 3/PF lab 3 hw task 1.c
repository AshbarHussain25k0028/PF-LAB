#include <stdio.h>
#include <string.h>
int main() {
    int Score1, Score2, Score3;
    int TotalScore;
    float percentage;
    printf("Enter the marks obtained in subject1 ");
    scanf("%d", &Score1);
    printf("Enter the marks obtained in subject 2 ");
    scanf("%d", &Score2);
    printf("Enter the marks obtained in subject 3 ");
    scanf("%d", &Score3);
    TotalScore = Score1 + Score2 + Score3;
    percentage = (float)TotalScore/ 300 * 100;
    printf("\nTotal Marks are : %d\n",TotalScore);
    printf("Percentage: %.2f", percentage);

}

