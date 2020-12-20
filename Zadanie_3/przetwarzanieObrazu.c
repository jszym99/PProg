#include <stdio.h>
#include <math.h>

#define M 3
#define N 7

void odwroc (int tablica [10][10], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            tablica[i][j] = -tablica[i][j];
        }
    }
}

void wyswietl(int tablica[10][10], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            if(abs(tablica[i][j]) < 10)
            {
                if(tablica[i][j] < 0)
                    printf( "   %d", tablica[i][j]);
                else
                    printf( "    %d", tablica[i][j]);
            }
            else
            {
                if(tablica[i][j] < 0)
                    printf( "  %d", tablica[i][j]);
                else
                    printf( "   %d", tablica[i][j]);
                
            }
        }
        printf("\n");
    }
}

void wypelnijTablice (int tablica[10][10], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            tablica[i][j] = i*j;
        }
    }
}


int main ()
{
    int tab[10][10];

    wypelnijTablice(tab, 10, 10);

    printf("Zawartosc oryginalna: \n");
    wyswietl(tab, M, N);

    odwroc(tab, M, N);

    printf("Zawartosc po zmianie znakow: \n");
    wyswietl(tab, M, N);

    return 0;
}