#include <stdio.h>
#include <math.h>

int main() {
    double alpha, beta;
    double z1, z2;

    printf("Variant 9\n");
    printf("Enter alpha (radians): ");
    if (scanf("%lf", &alpha) != 1) return 0;

    printf("Enter beta (radians): ");
    if (scanf("%lf", &beta) != 1) return 0;

    z1 = pow(cos(alpha) - cos(beta), 2.0)
       - pow(sin(alpha) - sin(beta), 2.0);

    z2 = -4.0 * pow(sin((alpha - beta) / 2.0), 2.0)
         * cos(alpha + beta);

    printf("\nResults:\n");
    printf("z1 = %.6f\n", z1);
    printf("z2 = %.6f\n", z2);
    printf("|z1 - z2| = %.6f\n", fabs(z1 - z2));

    return 0;
}
