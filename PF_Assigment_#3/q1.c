#include <stdio.h>
double calculateRepayment(double loan, double interestRate, int years)
{
    double installment = 40000;   
    if (loan <= 0 || years == 0)
    {
        return 0;
    }
    loan = loan + (loan * interestRate);
    if (loan <= installment)
    {
        printf("Year %d: Remaining loan = 0.00 (Final payment: %.2lf)\n", years, loan);
        return loan;   
    }
    loan = loan - installment;
    printf("Year %d: Remaining loan = %.2lf\n", years, loan);
    return installment + calculateRepayment(loan, interestRate, years - 1);
}
int main()
{
    double loan = 100000;
    double interestRate = 0.05;
    int years = 3;
    double total = calculateRepayment(loan, interestRate, years);
    printf("\nTotal repayment over %d years = %.2lf\n", years, total);
    return 0;
}

