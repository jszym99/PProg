#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "filtry.h"

#define PROCENT 0.01 // przelicznik procentów
#define RGB 3        // przetwarzanie jedengo z kolorów
#define DZIELNIK 3 // zmienna pomocnicza do liczenia średniej z 3 sąsiednich pikseli

void negatyw(t_obraz *obraz_odwr)
{
    for (int i = 0; i < obraz_odwr->wymy; i++)
    {
        for (int j = 0; j < (obraz_odwr->wymx * obraz_odwr->typ); j++)
        {
            if (obraz_odwr->kolor <= 0 || ((j + 1) % RGB == (obraz_odwr->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
                obraz_odwr->piksele[i][j] = (obraz_odwr->odcienie) - obraz_odwr->piksele[i][j];
        }
    }
}

void progowanie(t_obraz *obraz_prog, int prog)
{
    int nowy_prog = round(PROCENT * prog * obraz_prog->odcienie);

    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < (obraz_prog->wymx * obraz_prog->typ); j++)
        {
            if (obraz_prog->kolor <= 0 || ((j + 1) % RGB == (obraz_prog->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
            {
                if (obraz_prog->piksele[i][j] > nowy_prog)
                    obraz_prog->piksele[i][j] = obraz_prog->odcienie;
                else
                    obraz_prog->piksele[i][j] = 0;
            }
        }
    }
}

void polProgowanieBieli(t_obraz *obraz_prog, int prog_b)
{
    int nowy_prog_b = round(PROCENT * prog_b * obraz_prog->odcienie);

    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < (obraz_prog->wymx * obraz_prog->typ); j++)
        {
            if (obraz_prog->kolor <= 0 || ((j + 1) % RGB == (obraz_prog->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
            {
                if (obraz_prog->piksele[i][j] <= nowy_prog_b)
                    obraz_prog->piksele[i][j] = 0;
            }
        }
    }
}

void polProgowanieCzerni(t_obraz *obraz_prog, int prog_c)
{
    int nowy_prog_c = round(PROCENT * prog_c * obraz_prog->odcienie);

    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < (obraz_prog->wymx * obraz_prog->typ); j++)
        {
            if (obraz_prog->kolor <= 0 || ((j + 1) % RGB == (obraz_prog->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
            {
                if (obraz_prog->piksele[i][j] > nowy_prog_c)
                    obraz_prog->piksele[i][j] = obraz_prog->odcienie;
            }
        }
    }
}

void korGamma(t_obraz *obraz_gamma, float pGamma)
{
    for (int i = 0; i < obraz_gamma->wymy; i++)
    {
        for (int j = 0; j < (obraz_gamma->wymx * obraz_gamma->typ); j++)
        {
            if (obraz_gamma->kolor <= 0 || ((j + 1) % RGB == (obraz_gamma->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
                obraz_gamma->piksele[i][j] = round(pow((1.0 * (obraz_gamma->piksele[i][j]) / (obraz_gamma->odcienie)), (1 / pGamma)) * (obraz_gamma->odcienie));
        }
    }
}

void zmianaPoz(t_obraz *obraz_poziom, int czern, int biel)
{
    float multi = 1.0 * (obraz_poziom->odcienie) / (biel - czern);

    for (int i = 0; i < obraz_poziom->wymy; i++)
    {
        for (int j = 0; j < (obraz_poziom->wymx * obraz_poziom->typ); j++)
        {
            if (obraz_poziom->kolor <= 0 || ((j + 1) % RGB == (obraz_poziom->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
            {
                if (obraz_poziom->piksele[i][j] <= czern)
                    obraz_poziom->piksele[i][j] = 0;
                else if (obraz_poziom->piksele[i][j] >= biel)
                    obraz_poziom->piksele[i][j] = obraz_poziom->odcienie;
                else
                    obraz_poziom->piksele[i][j] = round((obraz_poziom->piksele[i][j] - czern) * multi);
            }
        }
    }
}

void kontur(t_obraz *obraz_kontur)
{
    for (int i = 0; i < obraz_kontur->wymy - 1; i++)
    {
        for (int j = 0; j < (obraz_kontur->wymx * obraz_kontur->typ) - obraz_kontur->typ; j++)
        {
            if (obraz_kontur->kolor <= 0 || ((j + 1) % RGB == (obraz_kontur->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
                obraz_kontur->piksele[i][j] = abs(obraz_kontur->piksele[i][j + obraz_kontur->typ] - obraz_kontur->piksele[i][j]) + abs(obraz_kontur->piksele[i + 1][j] - obraz_kontur->piksele[i][j]);

            if (obraz_kontur->piksele[i][j] > obraz_kontur->odcienie)
                obraz_kontur->piksele[i][j] = obraz_kontur->odcienie;
        }
    }
}

void rozmywaniePoz(t_obraz *obraz_rozmx)
{
    for (int i = 0; i < obraz_rozmx->wymy; i++)
    {
        for (int j = obraz_rozmx->typ; j < (obraz_rozmx->wymx * obraz_rozmx->typ) - obraz_rozmx->typ; j++)
        {
            if (obraz_rozmx->kolor <= 0 || ((j + 1) % RGB == (obraz_rozmx->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
                obraz_rozmx->piksele[i][j] = round((obraz_rozmx->piksele[i][j - obraz_rozmx->typ] + obraz_rozmx->piksele[i][j] + obraz_rozmx->piksele[i][j + obraz_rozmx->typ]) / DZIELNIK);
        }
    }
}

void rozmywaniePion(t_obraz *obraz_rozmy)
{
    for (int i = 1; i < obraz_rozmy->wymy - 1; i++)
    {
        for (int j = 0; j < (obraz_rozmy->wymx * obraz_rozmy->typ); j++)
        {
            if (obraz_rozmy->kolor <= 0 || ((j + 1) % RGB == (obraz_rozmy->kolor) % RGB)) //operacje tylko na pikselach o zadanym kolorze
                obraz_rozmy->piksele[i][j] = round((obraz_rozmy->piksele[i - 1][j] + obraz_rozmy->piksele[i][j] + obraz_rozmy->piksele[i + 1][j]) / DZIELNIK);
        }
    }
}

void rozciaganieHisto(t_obraz *obraz_histo) // TODO: zabezpieczyć przed przypadkiem (max-min)=0
{
    int min; // Najmniejsza wartość odcienia w obrazie (czerń)
    int max; // Największa wartość odcienia w obrazie (biel)

    if (obraz_histo->typ == 1) // dla obrazu czarno-białego
    {
        min = obraz_histo->piksele[0][0];
        max = obraz_histo->piksele[0][0];
    }
    else // dla obrazu kolorowego
    {
        min = obraz_histo->piksele[0][obraz_histo->kolor - 1];
        max = obraz_histo->piksele[0][obraz_histo->kolor - 1];
    }

    // Szukanie skrajnych wartości szarości w obrazie
    for (int i = 0; i < obraz_histo->wymy; i++)
    {
        for (int j = 0; j < (obraz_histo->wymx * obraz_histo->typ); j++)
        {
            if ((obraz_histo->kolor <= 0 || ((j + 1) % RGB == (obraz_histo->kolor) % RGB)) && obraz_histo->piksele[i][j] < min)
                min = obraz_histo->piksele[i][j];

            if ((obraz_histo->kolor <= 0 || ((j + 1) % RGB == (obraz_histo->kolor) % RGB)) && obraz_histo->piksele[i][j] > max)
                max = obraz_histo->piksele[i][j];
        }
    }

    //printf("%d %d\n", min, max);

    if ((max - min) != 0)
    {
        float multi = 1.0 * (obraz_histo->odcienie) / (max - min);
        //printf("%f\n", multi);
        for (int i = 0; i < obraz_histo->wymy; i++)
        {
            for (int j = 0; j < (obraz_histo->wymx * obraz_histo->typ); j++)
            {
                if (obraz_histo->kolor <= 0 || ((j + 1) % RGB == (obraz_histo->kolor) % RGB))
                    obraz_histo->piksele[i][j] = round((obraz_histo->piksele[i][j] - min) * multi);
            }
        }
    }
}

void szarosci(t_obraz *obraz_szary)
{
    
    for (int i = 0; i < obraz_szary->wymy; i++)
    {
        int k = 0; // zmienna pomocnicza do kolorów
        for (int j = 0; j < obraz_szary->wymx; j++)
        {
            obraz_szary->piksele[i][j] = round((obraz_szary->piksele[i][k] + obraz_szary->piksele[i][k+1] + obraz_szary->piksele[i][k+2])/RGB);
            k += RGB;
        }
    }

    obraz_szary->typ = 1; // teraz obraz jest czarnobiały (czyli P2)
    obraz_szary->kolor = 0; // już nie operujemy na żadnym kolorze

    // Zmniejszamy rozmiar tablicy przechowującej obraz
    for (int i = 0; i < obraz_szary->wymy; i++)
    {
        obraz_szary->piksele[i] = realloc(obraz_szary->piksele[i], obraz_szary->wymx * sizeof(int));
    }
}
