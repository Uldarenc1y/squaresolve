#include "function1.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>

const double EPS = 1e-8;

int SolutionSquareEq(double a, double b, double c, double* px1, double* px2)
{


    //assert
    assert(isfinite(a) == 1);
    assert(isfinite(b) == 1);
    assert(isfinite(c) == 1);
    assert(!(px1 == 0));
    assert(!(px2 == 0));

    double d = b*b - 4*a*c;

    if (isnul(a)) // a = 0?
        {
        if (isnul(b)) // a = 0, b ?= 0
          {
              if (isnul(c)) // a = 0, b = 0, c ?=0
                return INFINITY_ROOTS;
              return NO_ROOTS;
          }
        if (isnul(c)) // a = 0, c ?= 0
        {
            *px1 = 0;
            return ONE_ROOT;
        }
        else // a = 0
        {
            *px1 = -c/b;
            return ONE_ROOT;
        }

        }
    else if (d < 0) // discriminant ?< 0
        {
         return NO_ROOTS;
         }
    else if (isnul(d)) // discriminant ?= 0
           {
            *px1 = -b/(2*a);
        return ONE_ROOT;
           }
        *px1 = (-b - sqrt(d)) /(2*a); // discriminant ?> 0
        *px2 = (-b + sqrt(d)) /(2*a);

        return TWO_ROOT;

}
int Parity2Variebles(double a, double b) //check on parity 2 variebles
{
    if (fabs(a - b) < EPS)
        return 1;
    return 0;
}

int isnul(double i)
{
    return (fabs(i) < EPS); //zero comparison
}

void TestCase(struct correct_roots Numbers)
{

    double new_x1 = 0, new_x2 = 0; // for comparison with correct number of roots, correct roots
    int  newNROOTS = SolutionSquareEq(Numbers.a, Numbers.b, Numbers.c, &new_x1, &new_x2);
    if (!(newNROOTS == Numbers.NROOTS1))
        printf("Test results are incorrect with a = %lg, b = %lg, c = %lg\nFaked result:Number of roots - %d x1 = %lg x2 = %lg\n\
                  Expected %d number of solutions\nx1 = %lg\nx2 = %lg", Numbers.a, Numbers.b, Numbers.c, newNROOTS, new_x1, new_x2, Numbers.NROOTS1, Numbers.x1, Numbers.x2);
    else if (!(Parity2Variebles(new_x1, Numbers.x1) && Parity2Variebles(new_x2, Numbers.x2)))
        printf("with a = %lg, b = %lg, c = %lg fake x1 = %lg, fake x2 = %lg\n"
                  "expected x1 = %lg, x2 = %lg\n", Numbers.a, Numbers.b, Numbers.c, new_x1, new_x2, Numbers.x1, Numbers.x2);
}
