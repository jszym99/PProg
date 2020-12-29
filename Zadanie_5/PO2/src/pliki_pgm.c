#include <stdio.h>
#include <stdlib.h>
#include "pliki_pgm.h"

#define DL_LINII 1024

int czytaj(FILE *plik_we, t_obraz *obraz_pgm)
{
    char buf[DL_LINII]; /* bufor pomocniczy do czytania naglowka i komentarzy */
    int znak;           /* zmienna pomocnicza do czytania komentarzy */
    int koniec = 0;     /* czy napotkano koniec danych w pliku */
    int i, j;

    /*Sprawdzenie czy podano prawidłowy uchwyt pliku */
    if (plik_we == NULL)
    {
        fprintf(stderr, "Blad: Nie podano uchwytu do pliku\n");
        return (0);
    }

    /* Sprawdzenie "numeru magicznego" - powinien być P2 lub P3 */
    if (fgets(buf, DL_LINII, plik_we) == NULL) /* Wczytanie pierwszej linii pliku do bufora */
        koniec = 1;                            /* Nie udalo sie? Koniec danych! */

    /* Czy jest magiczne "P2 lub P3"? */
    if ((buf[0] != 'P') || (buf[1] != '2') && (buf[1] != '3') || koniec)
    { 
        fprintf(stderr, "Blad: To nie jest plik PGM\n");
        return (0);
    }

    if((buf[0] == 'P') && (buf[1] == '3'))
        obraz_pgm->typ = 3; // obraz jest kolorowy
    else
        obraz_pgm->typ = 1; // obraz jest czarno-biały

    /* Pominiecie komentarzy */
    do
    {
        if ((znak = fgetc(plik_we)) == '#')
        {                                              /* Czy linia rozpoczyna sie od znaku '#'? */
            if (fgets(buf, DL_LINII, plik_we) == NULL) /* Przeczytaj ja do bufora                */
                koniec = 1;                            /* Zapamietaj ewentualny koniec danych */
        }
        else
        {
            ungetc(znak, plik_we);    /* Gdy przeczytany znak z poczatku linii */
        }                             /* nie jest '#' zwroc go                 */
    } while (znak == '#' && !koniec); /* Powtarzaj dopoki sa linie komentarza */
                                      /* i nie nastapil koniec danych         */

    /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
    if (fscanf(plik_we, "%d %d %d", &(obraz_pgm->wymx), &(obraz_pgm->wymy), &(obraz_pgm->odcienie)) != 3)
    {
        fprintf(stderr, "Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
        return (0);
    }

    /* Alokowanie pamięci dla tablicy */
    obraz_pgm->piksele = malloc(obraz_pgm->wymy * sizeof(int *));
    //if(*obraz_pgm == NULL)
        //printf("Blad: Nie udalo sie przypisac pamiecio");
    for(int i = 0; i < obraz_pgm->wymy; i++)
    {
        obraz_pgm->piksele[i] = malloc(obraz_pgm->typ * obraz_pgm->wymx * sizeof(int)); // 3x więcej jeśli obraz jest kolorowy
        //if((*obraz_pgm)[i] == NULL)
            //printf("Blad: Nie udalo sie przypisac pamiecio");
    }

    /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
    for (i = 0; i < obraz_pgm->wymy; i++)
    {
        for (j = 0; j < (obraz_pgm->wymx * obraz_pgm->typ); j++)
        {
            if (fscanf(plik_we, "%d", &(obraz_pgm->piksele)[i][j]) != 1)
            {
                fprintf(stderr, "Blad: Niewlasciwe wymiary obrazu\n");
                return (0);
            }
            //printf("%d ", obraz_pgm->piksele[i][j]);
        }
    }
    return obraz_pgm->wymx * obraz_pgm->wymy; /* Czytanie zakonczone sukcesem    */
} /* Zwroc liczbe wczytanych pikseli */

void zapisz (FILE *plik_wy, t_obraz *obraz_zapisz)
{
    /*Sprawdzenie czy podano prawidłowy uchwyt pliku */
    if (plik_wy == NULL)
    {
        fprintf(stderr, "Blad: Nie podano uchwytu do pliku\n");
    }

    if(obraz_zapisz->typ == 1)
        fprintf(plik_wy, "P2\n");
    else if(obraz_zapisz->typ == 3)
        fprintf(plik_wy, "P3\n");

    fprintf(plik_wy, "# Komentarz\n");
    fprintf(plik_wy, "%d %d\n", obraz_zapisz->wymx, obraz_zapisz->wymy);
    fprintf(plik_wy, "%d\n", obraz_zapisz->odcienie);
    for (int i = 0; i < obraz_zapisz->wymy; i++)
    {
        for (int j = 0; j < (obraz_zapisz->wymx * obraz_zapisz->typ); j++)
        {
            fprintf(plik_wy, "%d ", obraz_zapisz->piksele[i][j]);
        }
    }
}