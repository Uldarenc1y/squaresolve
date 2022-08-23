#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const double EPS = 1e-8;
int isnul(double i)
{
return (abs(i) > EPS);//sravnivanie s 0

}
int func(double a, double b, double c, double* px1, double* px2, double* px)
{
    double d;
    d = pow(b, 2) - 4*a*c;
    if (isnul(a))
        {
        if (isnul(b))
          {
              if (isnul(c))
                return 3;
             else
                return 0;
          }
        else
        {
            *px = -c/b;
            return 1;
        }

        }
    else if (d < 0)
     {
         return 0;
     }
    else if (d == 0)
        {
            *px = -b/2/a;
        return 1;
        }
    else
      {
        *px1 = (-b - sqrt(d)) /2/a;
        *px2 = (-b + sqrt(d)) /2/a;
        return 2;
      }
}

int main()
{
    double a, b, c;
    printf("enter a, b, c\n");
    int p = scanf("%lf%lf%lf", &a, &b, &c);
    int y;
    if p < 3
    {   continue;
        while ((y = getchar()) != '\n' || y = getchar()) != ' ')
    }


    double x1, x2, x;
    int n;
    n = func(a, b, c, &x1, &x2, &x);
    switch(n)
    {
        case 0:
            printf("no roots");
            break;
        case 1:
            printf("x = %lf", x);
            break;
        case 2:
            printf("x1 = %lf\nx2 = %lf", x1, x2);
            break;
        case 3:
            printf("an infinite number of solutions");
    }

    return 0;
    }
