#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filtry.h"
#include "pliki_pgm.h"

//#define MAX 512       /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024 /* Dlugosc buforow pomocniczych */

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

int main()
{
    t_obraz obraz;

    int odczytano, prog = 0;
    FILE *plik;
    char nazwa[100];

    /* Wczytanie zawartosci wskazanego pliku do pamieci */
    printf("Podaj nazwe pliku:\n");
    scanf("%s", nazwa);
    plik = fopen(nazwa, "r");

    /* Wczytaj dane z pliku jeśli plik istnieje */
    if (plik != NULL)
    { /* co spowoduje zakomentowanie tego warunku */
        odczytano = czytaj(plik, &obraz);
        fclose(plik);
    }

    //printf("%d\n", odczytano);

    //Odwróć i zapisz plik
    if (plik != NULL)
    {
        //negatyw(&obraz);
        printf("Podaj wartosc progu:\n");
        scanf("%d", &prog);

        polProgowanieCzerni(&obraz, prog);
    }
    
    printf("Podaj nazwe pliku wyjsciowego:\n");
    scanf("%s", nazwa);
    plik = fopen(nazwa, "w");


    /* Zapisywanie przetworzonego obrazu do pliku */
    if (plik != NULL)
    {
        zapisz(plik, &obraz);
        fclose(plik);
    }


    /* Zwalnianie pamięci przypisanej do tablicy */
    for(int i = 0; i < obraz.wymy; i++)
    {
        free(obraz.piksele[i]);
    }
    free(obraz.piksele);


    /* Wyswietlenie poprawnie wczytanego obrazu zewnetrznym programem */
    if (odczytano != 0)
        wyswietl(nazwa);

    return odczytano;
}