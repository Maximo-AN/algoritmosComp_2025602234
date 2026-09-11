#include <stdio.h>
#include <math.h>

int main() {
    double a = 4, u = 6, c = 1, 
    r = 12, m = 3, n = 7, z = 30, w = 2, p = 31;
    double result;

    result = p - (sqrt(a) * (u - c) + ((r / m) * n - (pow(u, 2) - z)) - w);

    printf("%.2f\n", result);
    
    return 0;
}