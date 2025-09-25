#include <stdio.h>

double polynomial (double x) {
    double p = x * x;           
    double t = (p + 1) * (p + x); 
    return t + 1;
}

int main() {
    double x;
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("%.2f\n", polynomial(x));
    return 0;
}