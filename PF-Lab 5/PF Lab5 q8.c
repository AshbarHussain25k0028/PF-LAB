#include <stdio.h>
#include <math.h>
int main() {
    double loan, rate, time, interest, total, emi;
    int type;
    printf("Enter loan amount");
    scanf("%lf", &loan);
    printf("Enter time in years");
    scanf("%lf", &time);
    printf("Enter annual interest rate");
    scanf("%lf", &rate);
    printf("Enter interest type 1.Simple, 2.Compound");
    scanf("%d", &type);

    if (type == 1) {
        interest = (loan * rate * time) / 100;
        total = loan + interest;
        emi = total / (time * 12);
        printf("EMI (Simple Interest) = %.2lf\n", emi);
    } else {
        if (type == 2) {
            total = loan * pow((1 + rate / 100), time);
            emi = total / (time * 12);
            printf("EMI ( compount interest) = %.2lf\n", emi);
        } else {
            printf("Invalid interest type\n");
        }
    }
    return 0;
}

