#include <stdio.h>


// Zdefiniowanie prostokątów A, B i W (wynik) dla łatwości zapisu (i zgodniśći z opisame zadania w udostępnionych materiałąch)
#define A tab[0]
#define B tab[1]
#define W tab[2]

struct coord
{
    int x1;
    int y1;
    int x2;
    int y2;
}tab[3];

int max (int a, int b) //sprawdzanie któraz z wartości jest większa
{
    if (a >= b)
        return a;
    else 
        return b;
}

int min (int a, int b) //sprawdzanie któraz z wartości jest mniejsza
{
    if (a <= b)
        return a;
    else 
        return b;
}

int main ()
{
    A.x1 = 1; //spółrzędna x lewego dolnego rogu prostokąta A
    A.y1 = 1; //spółrzędna y lewego dolnego rogu prostokąta A

    A.x2 = 1; //spółrzędna x prawego górnego rogu prostokąta A
    A.y2 = 10; //spółrzędna y prawego górnego rogu prostokąta A

    B.x1 = 4; //spółrzędna x lewego dolnego rogu prostokąta B
    B.y1 = 4; //spółrzędna y lewego dolnego rogu prostokąta B
    
    B.x2 = 12; //spółrzędna x prawego górnego rogu prostokąta A
    B.y2 = 12; //spółrzędna y prawego górnego rogu prostokąta A

    W.x1 = max(A.x1, B.x1);
    W.y1 = min(A.y1, B.y1);
    W.x2 = max(A.x2, B.x2);
    W.y2 = min(A.y2, B.y2);

    printf("Wspolrzedne lewego dolnego i prawego gornego rodu czesci wspolnej prostokatow A i B\n");
    printf("W.x1 = %d\nW.y1 = %d\nW.x2 = %d\nW.y2 = %d\n", W.x1, W.y1, W.x2, W.y2);

    return 0;
}