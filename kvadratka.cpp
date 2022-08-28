#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "function1.h"

int main()
{   printf("enter a, b, c for solving the square equation\n");
    double a = 0, b = 0, c = 0;
    int p = scanf("%lf%lf%lf", &a, &b, &c);
    while (p < 3)
    {
        while (getchar () != '\n'){};
        printf("enter a, b, c again\n");
        p = scanf("%lf%lf%lf", &a, &b, &c);
    }

    double x1 = 0, x2 = 0;
    int n = SolutionSquareEq(a, b, c, &x1, &x2);

    switch(n)
    {
        case NO_ROOTS:
            printf("no roots\n");
            break;

        case ONE_ROOT:
            printf("x = %lg\n", x1);
            break;

        case TWO_ROOT:
            printf("x1 = %lg\nx2 = %lg\n", x1, x2);
            break;

        case INFINITY_ROOTS:
            printf("an infinite number of solutions\n");
            break;
    }

    struct correct_roots Numbers [5] = {1, 2, 3, 0,  0, 0,      0, 2, 3, 1, -1.5, 0,     0, 0, 0, 17, 0, 0,      0, 7, 0, 1, 0, 0,   1, 1, 1, 0, 0, 0};
    int number_of_checks = sizeof(Numbers) / sizeof(Numbers[0]);
    for (int i = 0; i < number_of_checks; ++i)
    {
        TestCase(Numbers[i]);
    }

    return 0;
}
