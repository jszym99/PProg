#include <stdio.h>
#include <math.h>

int main ()
{
    double a = 3, b = 2, c = -1, delta = 0;

    if(a == 0)
    {
        if(b != 0)
        {
            printf("x = %lf", (-c)/b);
            return 0;
        }
        else
        {
            printf("Blad danych wejsciowych: a = 0, b = 0 \nRownanie nie jest kwadratowe\ny = %lf", c);
            return 0;
        }
    }

    delta = (b*b)-4*(a*c);
    printf("Delta = %lf\n", delta);


    if(delta == 0)
    {
        double x = -b/(a*2);
        printf("x = %lf\n", x);
    }
    else if(delta > 0)
    {
        double x1 = 0, x2 = 0;
        x1 = (-b+sqrt(delta))/(2*a);
        x2 = (-b-sqrt(delta))/(2*a);
        printf("x1 = %lf\n", x1);
        printf("x2 = %lf\n", x2);            
    }
    else
    {
        printf("Brak rozwiazan w zbiorze liczb rzerczywistych");
    }

    return 0;
}
