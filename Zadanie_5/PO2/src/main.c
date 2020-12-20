#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filtry.h"

#define MAX 512       /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024 /* Dlugosc buforow pomocniczych */

/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	       	       	       	    *
 *										    *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM			    *
 * \param[out] obraz_pgm tablica, do ktorej zostanie zapisany obraz		    *
 * \param[out] wymx szerokosc obrazka						    *
 * \param[out] wymy wysokosc obrazka						    *
 * \param[out] szarosci liczba odcieni szarosci					    *
 * \return liczba wczytanych pikseli						    *
 ************************************************************************************/

int czytaj(FILE *plik_we, int *(**obraz_pgm), int *wymx, int *wymy, int *szarosci)
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

    /* Sprawdzenie "numeru magicznego" - powinien być P2 */
    if (fgets(buf, DL_LINII, plik_we) == NULL) /* Wczytanie pierwszej linii pliku do bufora */
        koniec = 1;                            /* Nie udalo sie? Koniec danych! */

    if ((buf[0] != 'P') || (buf[1] != '2') || koniec)
    { /* Czy jest magiczne "P2"? */
        fprintf(stderr, "Blad: To nie jest plik PGM\n");
        return (0);
    }

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
    if (fscanf(plik_we, "%d %d %d", wymx, wymy, szarosci) != 3)
    {
        fprintf(stderr, "Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
        return (0);
    }

    /* Alokowanie pamięci dla tablicy */
    *obraz_pgm = malloc(*wymy * sizeof(int *));
    if(*obraz_pgm == NULL)
        printf("Blad: Nie udalo sie przypisac pamiecio");
    for(int i = 0; i < *wymy; i++)
    {
        (*obraz_pgm)[i] = malloc(*wymx * sizeof(int));
        if((*obraz_pgm)[i] == NULL)
            printf("Blad: Nie udalo sie przypisac pamiecio");
    }

    /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
    for (i = 0; i < *wymy; i++)
    {
        for (j = 0; j < *wymx; j++)
        {
            if (fscanf(plik_we, "%d", &(*obraz_pgm)[i][j]) != 1)
            {
                fprintf(stderr, "Blad: Niewlasciwe wymiary obrazu\n");
                return (0);
            }
        }
    }
    return *wymx * *wymy; /* Czytanie zakonczone sukcesem    */
} /* Zwroc liczbe wczytanych pikseli */

/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku)
{
    char polecenie[DL_LINII]; /* bufor pomocniczy do zestawienia polecenia */

    strcpy(polecenie, "start "); /* konstrukcja polecenia postaci */
    strcat(polecenie, n_pliku);  /* display "nazwa_pliku" &       */
    strcat(polecenie, " &");
    printf("%s\n", polecenie); /* wydruk kontrolny polecenia */
    system(polecenie);         /* wykonanie polecenia        */
}

/*void negatyw (int *(**obraz_odwr), int *wymx, int *wymy, int *skala)
{
    for (int i = 0; i < *wymy; i++)
    {
        for (int j = 0; j < *wymx; j++)
        {
            (*obraz_odwr)[i][j] = (*skala) - (*obraz_odwr)[i][j];
        }
    }
}*/

void zapisz (FILE *plik_wy, int *(**obraz_zapisz), int *wymx, int *wymy, int *skala)
{
    fprintf(plik_wy, "P2\n");
    fprintf(plik_wy, "# Komentarz\n");
    fprintf(plik_wy, "%d %d\n", *wymx, *wymy);
    fprintf(plik_wy, "%d\n", *skala);
    for (int i = 0; i < *wymy; i++)
    {
        for (int j = 0; j < *wymx; j++)
        {
            fprintf(plik_wy, "%d ",(*obraz_zapisz)[i][j]);
        }
    }
}

int main()
{
    int **obraz = NULL;
    //int rozmObr = MAX;
    int wymx, wymy, odcieni;

    /*obraz = malloc(rozmObr * sizeof(int *));
    for(int i = 0; i < rozmObr; i++)
        obraz[i] = malloc(rozmObr * sizeof(int));*/

    int odczytano = 0;
    FILE *plik;
    char nazwa[100];

    /* Wczytanie zawartosci wskazanego pliku do pamieci */
    printf("Podaj nazwe pliku:\n");
    scanf("%s", nazwa);
    plik = fopen(nazwa, "r");

    if (plik != NULL)
    { /* co spowoduje zakomentowanie tego warunku */
        odczytano = czytaj(plik, &obraz, &wymx, &wymy, &odcieni);
        fclose(plik);
    }

    if (plik != NULL)
        {
            negatyw(&obraz, &wymx, &wymy, &odcieni);
            fclose(plik);
        }
    /* Wyswietlenie poprawnie wczytanego obrazu zewnetrznym programem */
    //if (odczytano != 0)
        //wyswietl(nazwa);

    //Odwróć i zapisz plik
    printf("Podaj nazwe pliku wyjsciowego:\n");
    scanf("%s", nazwa);
    plik = fopen(nazwa, "w");

    if (plik != NULL)
    {
        zapisz(plik, &obraz, &wymx, &wymy, &odcieni);
        fclose(plik);
    }

    wyswietl(nazwa);

    for(int i = 0; i < wymy; i++)
    {
        free(obraz[i]);
        obraz[i] = NULL;
    }
    free(obraz);
    obraz = NULL;
    return odczytano;
}