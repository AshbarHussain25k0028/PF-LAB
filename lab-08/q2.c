#include <stdio.h>

float calculateBonus(float salary);

int main() {
    float salary[5], bonus, totalPayout = 0;
    int i;
    for(i = 0; i < 5; i++) {
        printf("Enter salary of Employee %d: ", i + 1);
        scanf("%f", &salary[i]);
    }
    for(i = 0; i < 5; i++) {
        bonus = calculateBonus(salary[i]);
        printf("Employee %d Bonus: %.2f\n", i + 1, bonus);
        totalPayout += salary[i] + bonus;
    }
    printf("Total Payout: %.2f\n", totalPayout);
    return 0;
}

float calculateBonus(float salary) {
    if(salary < 30000)
        return salary * 0.20;
    else
        return salary * 0.10;
}

