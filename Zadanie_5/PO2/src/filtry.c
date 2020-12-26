#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "filtry.h"

void negatyw (t_obraz *obraz_odwr)
{
    for (int i = 0; i < obraz_odwr->wymy; i++)
    {
        for (int j = 0; j < obraz_odwr->wymx; j++)
        {
            obraz_odwr->piksele[i][j] = (obraz_odwr->odcienie) - obraz_odwr->piksele[i][j];
        }
    }
}

void progowanie(t_obraz *obraz_prog, int prog)
{
    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < obraz_prog->wymx; j++)
        {
            if(obraz_prog->piksele[i][j] > prog)
                obraz_prog->piksele[i][j] = obraz_prog->odcienie;
            else
                obraz_prog->piksele[i][j] = 0;
        }
    }
}

void polProgowanieBieli(t_obraz *obraz_prog, int prog_b)
{
    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < obraz_prog->wymx; j++)
        {
            if(obraz_prog->piksele[i][j] <= prog_b)
                obraz_prog->piksele[i][j] = 0;
        }
    }
}

void polProgowanieCzerni(t_obraz *obraz_prog, int prog_c)
{
    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < obraz_prog->wymx; j++)
        {
            if(obraz_prog->piksele[i][j] > prog_c)
                obraz_prog->piksele[i][j] = obraz_prog->odcienie;
        }
    }
}

void gamma(t_obraz *obraz_gamma, float pGamma) // TODO: zabezpieczyć przed gamma=0
{
    for (int i = 0; i < obraz_gamma->wymy; i++)
    {
        for (int j = 0; j < obraz_gamma->wymx; j++)
        {
            obraz_gamma->piksele[i][j] = round(pow((1.0*(obraz_gamma->piksele[i][j])/(obraz_gamma->odcienie)), (1/pGamma))*(obraz_gamma->odcienie));
        }
    }
}

void zmianaPoz(t_obraz *obraz_poziom, int czern, int biel) // TODO: zabezpieczyć przed przypadkiem (biel-czern)=0
{
    float multi = 1.0*(obraz_poziom->odcienie)/(biel-czern);

    for (int i = 0; i < obraz_poziom->wymy; i++)
    {
        for (int j = 0; j < obraz_poziom->wymx; j++)
        {
            if(obraz_poziom->piksele[i][j] <= czern)
                obraz_poziom->piksele[i][j] = 0;
            else if (obraz_poziom->piksele[i][j] >= biel)
                obraz_poziom->piksele[i][j] = obraz_poziom->odcienie;
            else
                obraz_poziom->piksele[i][j] = round((obraz_poziom->piksele[i][j] - czern)*multi);
        }
    }
}

void kontur(t_obraz *obraz_kontur)
{
    for (int i = 0; i < obraz_kontur->wymy - 1; i++)
    {
        for (int j = 0; j < obraz_kontur->wymx - 1; j++)
        {
            obraz_kontur->piksele[i][j] = abs(obraz_kontur->piksele[i][j+1]  - obraz_kontur->piksele[i][j]) + abs(obraz_kontur->piksele[i+1][j] - obraz_kontur->piksele[i][j]);
        }
    }
}

void rozmywaniePoz(t_obraz *obraz_rozmx)
{
    for (int i = 0; i < obraz_rozmx->wymy; i++)
    {
        for (int j = 1; j < obraz_rozmx->wymx - 1; j++)
        {
            obraz_rozmx->piksele[i][j] = round((obraz_rozmx->piksele[i][j-1] + obraz_rozmx->piksele[i][j] + obraz_rozmx->piksele[i][j+1])/3);
        }
    }
}

void rozmywaniePion(t_obraz *obraz_rozmy)
{
    for (int i = 1; i < obraz_rozmy->wymy - 1; i++)
    {
        for (int j = 0; j < obraz_rozmy->wymx; j++)
        {
            obraz_rozmy->piksele[i][j] = round((obraz_rozmy->piksele[i-1][j] + obraz_rozmy->piksele[i][j] + obraz_rozmy->piksele[i+1][j])/3);
        }
    }
}

void rozciaganieHisto(t_obraz *obraz_histo) // TODO: zabezpieczyć przed przypadkiem (max-min)=0
{
    int min = obraz_histo->piksele[0][0]; // Najmniejsza wartość odcienia w obrazie (czerń)
    int max = obraz_histo->piksele[0][0]; // Największa wartość odcienia w obrazie (biel)

    // Szukanie skrajnych wartości szarości w obrazie
    for (int i = 0; i < obraz_histo->wymy; i++)
    {
        for (int j = 0; j < obraz_histo->wymx; j++)
        {
            if(obraz_histo->piksele[i][j] < min)
                min = obraz_histo->piksele[i][j];

            if(obraz_histo->piksele[i][j] > max)
                max = obraz_histo->piksele[i][j];
        }
    }

    float multi = 1.0*(obraz_histo->odcienie)/(max - min);
    printf("%f\n", multi);
    for (int i = 0; i < obraz_histo->wymy; i++)
    {
        for (int j = 0; j < obraz_histo->wymx; j++)
        {
            obraz_histo->piksele[i][j] = round((obraz_histo->piksele[i][j] - min) * multi);
        }
    }
}
