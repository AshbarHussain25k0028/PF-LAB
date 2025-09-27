#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c, discriminant, r1, r2;
    printf("Enter  a: ");
    scanf("%lf", &a);
    printf("Enter  b: ");
    scanf("%lf", &b);
    printf("Enter  c: ");
    scanf("%lf", &c);
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        r1 = (-b + sqrt(discriminant)) / (2 * a);
        r2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct: r1 = %.2lf, r2 = %.2lf\n", r1, r2);
    } else {
        if (discriminant == 0) {
            r1 = r2 = -b / (2 * a);
            printf("Roots are real and equal: r1 = r2 = %.2lf\n", r1);
        } else {
            double realP = -b / (2 * a);
            double imaginaryP = sqrt(-discriminant) / (2 * a);
            printf("Roots are imaginary: r1 = %.2lf + %.2lfi, r2 = %.2lf - %.2lfi\n", realP, imaginaryP, realP, imaginaryP);
        }
    }
    return 0;
}

