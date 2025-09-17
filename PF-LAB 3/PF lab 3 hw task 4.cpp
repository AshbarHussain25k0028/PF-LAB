#include <stdio.h>
int main() {
    float BasicSalary, HRA, DA,GrossSalary;
    printf("Enter the employee's basic salary: ");
    scanf("%f", &BasicSalary);
    HRA= 0.10 * BasicSalary; 
    DA= 0.05 * BasicSalary;  
    GrossSalary = BasicSalary + HRA + DA;
    printf("\n--- Salary Details ---\n");
    printf("Basic Salary: %.2f\n",BasicSalary);
    printf("House Rent Allowance : %.2f\n",HRA);
    printf("Dearness Allowance : %.2f\n",DA);
    printf("Gross Salary: %.2f\n",GrossSalary);

   
}

