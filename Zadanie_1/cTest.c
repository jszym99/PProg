#include <stdio.h>


// Zdefiniowanie prostokątów A, B i W (wynik) dla łatwości zapisu
#define A tab[0]
#define B tab[1]
#define W tab[2]

struct coord
{
    float x1;
    float y1;
}tab[3];


int main ()
{
    A.x1 = 1;
    A.y1 = 1;
    B.x1 = 4;
    B.y1 = 4;

    printf("%lf",A.x1);
}