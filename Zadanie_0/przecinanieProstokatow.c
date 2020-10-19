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
    A.x1 = 3; //spółrzędna x lewego górnego rogu prostokąta A
    A.y1 = 3; //spółrzędna y lewego górnego rogu prostokąta A

    A.x2 = 5; //spółrzędna x prawego dolnego rogu prostokąta A
    A.y2 = 1; //spółrzędna y prawego dolnego rogu prostokąta A

    B.x1 = 2; //spółrzędna x lewego górnego rogu prostokąta B
    B.y1 = 4; //spółrzędna y lewego górnego rogu prostokąta B
    
    B.x2 = 4; //spółrzędna x prawego dolnego rogu prostokąta A
    B.y2 = 2; //spółrzędna y prawego dolnego rogu prostokąta A

    if(A.x1 == A.x2 || A.y1 == A.y2)
    {
        if(A.x1 == A.y1 && A.x2 == A.y2)
            printf("Prostokat A jest punktem");
        else
            printf("Prostokat A jest prosta");
    } else if(B.x1 == B.x2 || B.y1 == B.y2)
    {
        if(B.x1 == B.y1 && B.x2 == B.y2)
            printf("Prostokat B jest punktem");
        else
            printf("Prostokat B jest prosta");
    }else{
        W.x1 = max(A.x1, B.x1);
        W.y1 = min(A.y1, B.y1);
        W.x2 = min(A.x2, B.x2);
        W.y2 = max(A.y2, B.y2);

        printf("Wspolrzedne lewego gornego i prawego dolnego rodu czesci wspolnej prostokatow A i B\n");
        printf("W.x1 = %d\nW.y1 = %d\nW.x2 = %d\nW.y2 = %d\n", W.x1, W.y1, W.x2, W.y2);
    }

    return 0;
}