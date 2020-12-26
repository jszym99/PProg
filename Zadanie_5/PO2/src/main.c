#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filtry.h"
#include "pliki_pgm.h"

#define DL_LINII 1024 /* Dlugosc buforow pomocniczych */

#define W_OK 0                /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1 /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY -2
#define B_BRAKWARTOSCI -3
#define B_BRAKPLIKU -4

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

void wyzeruj_opcje(t_opcje *wybor)
{
    wybor->plik_we = NULL;
    wybor->plik_wy = NULL;
    wybor->negatyw = 0;
    wybor->konturowanie = 0;
    wybor->progowanie = 0;
    wybor->pol_prog_biel = 0;
    wybor->pol_prog_czern = 0;
    wybor->gamma = 0;
    wybor->zmiana_poz = 0;
    wybor->rozm_x = 0;
    wybor->rozm_y = 0;
    wybor->roz_histo = 0;
    wybor->wyswietlenie = 0;
}

int przetwarzaj_opcje(int argc, char **argv, t_opcje *wybor)
{
    int prog;
    float pGamma;
    char *nazwa_pliku_we, *nazwa_pliku_wy;

    wyzeruj_opcje(wybor);
    wybor->plik_wy = stdout; /* na wypadek gdy nie podano opcji "-o" */

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-') /* blad: to nie jest opcja - brak znaku "-" */
            return B_NIEPOPRAWNAOPCJA;
        switch (argv[i][1])
        {
        case 'i': /* opcja z nazwa pliku wejsciowego */
        {
            if (++i < argc)
            { /* wczytujemy kolejny argument jako nazwe pliku */
                nazwa_pliku_we = argv[i];
                if (strcmp(nazwa_pliku_we, "-") == 0) /* gdy nazwa jest "-"        */
                    wybor->plik_we = stdin;           /* ustwiamy wejscie na stdin */
                else                                  /* otwieramy wskazany plik   */
                    wybor->plik_we = fopen(nazwa_pliku_we, "r");
            }
            else
                return B_BRAKNAZWY; /* blad: brak nazwy pliku */
            break;
        }
        case 'o': /* opcja z nazwa pliku wyjsciowego */
        {
            if (++i < argc)
            { /* wczytujemy kolejny argument jako nazwe pliku */
                nazwa_pliku_wy = argv[i];
                if (strcmp(nazwa_pliku_wy, "-") == 0) /* gdy nazwa jest "-"         */
                    wybor->plik_wy = stdout;          /* ustwiamy wyjscie na stdout */
                else                                  /* otwieramy wskazany plik    */
                    wybor->plik_wy = fopen(nazwa_pliku_wy, "w");
            }
            else
                return B_BRAKNAZWY; /* blad: brak nazwy pliku */
            break;
        }
        case 'p': // prog
        {
            if (argv[i][2] == 0)
            {
                if (++i < argc)
                { /* wczytujemy kolejny argument jako wartosc progu */
                    if (sscanf(argv[i], "%d", &prog) == 1)
                    {
                        wybor->progowanie = 1;
                        wybor->w_progu = prog;
                    }
                    else
                        return B_BRAKWARTOSCI; /* blad: niepoprawna wartosc progu */
                }
                else
                    return B_BRAKWARTOSCI; /* blad: brak wartosci progu */
                break;
            }
            else if (argv[i][2] == 'b')
            {
                if (++i < argc)
                { /* wczytujemy kolejny argument jako wartosc progu */
                    if (sscanf(argv[i], "%d", &prog) == 1)
                    {
                        wybor->pol_prog_biel = 1;
                        wybor->w_progu = prog;
                    }
                    else
                        return B_BRAKWARTOSCI; /* blad: niepoprawna wartosc progu */
                }
                else
                    return B_BRAKWARTOSCI; /* blad: brak wartosci progu */
                break;
            }
            else if (argv[i][2] == 'c')
            {
                if (++i < argc)
                { /* wczytujemy kolejny argument jako wartosc progu */
                    if (sscanf(argv[i], "%d", &prog) == 1)
                    {
                        wybor->pol_prog_czern = 1;
                        wybor->w_progu = prog;
                    }
                    else
                        return B_BRAKWARTOSCI; /* blad: niepoprawna wartosc progu */
                }
                else
                    return B_BRAKWARTOSCI; /* blad: brak wartosci progu */
                break;
            }else
                return B_NIEPOPRAWNAOPCJA;                
        }
        case 'g': // gamma
        {
            if (++i < argc)
            { /* wczytujemy kolejny argument jako wartosc progu */
                if (sscanf(argv[i], "%f", &pGamma) == 1)
                {
                    wybor->gamma = 1;
                    wybor->w_gamma = pGamma;
                }
                else
                    return B_BRAKWARTOSCI; /* blad: niepoprawna wartosc progu */
            }
            else
                return B_BRAKWARTOSCI; /* blad: brak wartosci progu */
            break;
        }
        case 'z':
        {
            if (++i < argc)
            {                                          /* wczytujemy kolejny argument jako wartosc progu */
                if (sscanf(argv[i], "%d", &prog) == 1) //TODO: wczytywanie 2 wartości
                {
                    wybor->progowanie = 1;
                    wybor->w_progu = prog;
                }
                else
                    return B_BRAKWARTOSCI; /* blad: niepoprawna wartosc progu */
            }
            else
                return B_BRAKWARTOSCI; /* blad: brak wartosci progu */
            break;
        }
        case 'n': /* mamy wykonac negatyw */
        {
            wybor->negatyw = 1;
            break;
        }
        case 'k': /* mamy wykonac konturowanie */
        {
            wybor->konturowanie = 1;
            break;
        }
        case 'r': // rozmywanie poziome
        {
            if (argv[i][2] == 'x')
                wybor->rozm_x = 1;
            else if (argv[i][2] == 'y')
                wybor->rozm_y = 1;
            else
                return B_NIEPOPRAWNAOPCJA;
            break;
        }
        case 'h': // rozciąganie histogramu
        {
            wybor->roz_histo = 1;
            break;
        }
        case 'd': /* mamy wyswietlic obraz */
        {
            wybor->wyswietlenie = 1;
            break;
        }
        default: /* nierozpoznana opcja */
            return B_NIEPOPRAWNAOPCJA;
        } /*koniec switch */
    }     /* koniec for */

    if (wybor->plik_we != NULL) /* ok: wej. strumien danych zainicjowany */
        return W_OK;
    else
        return B_BRAKPLIKU; /* blad:  nie otwarto pliku wejsciowego  */
}

int main(int argc, char **argv)
{
    t_obraz obraz;

    t_opcje opcje;

    int odczytano = 0; // ilość pikseli odczytanych z pliku
    int flaga = 0;

    flaga = przetwarzaj_opcje(argc, argv, &opcje);

    if (!flaga)
    {
        odczytano = czytaj(opcje.plik_we, &obraz);
        fclose(opcje.plik_we);

        //printf("%d\n", odczytano);

        if (opcje.negatyw)
            negatyw(&obraz);
        if (opcje.progowanie)
            progowanie(&obraz, opcje.w_progu);
        if (opcje.pol_prog_biel)
            polProgowanieBieli(&obraz, opcje.w_progu);
        if (opcje.pol_prog_czern)
            polProgowanieCzerni(&obraz, opcje.w_progu);
        if (opcje.gamma)
            gamma(&obraz, opcje.w_gamma);
        if (opcje.zmiana_poz)
            zmianaPoz(&obraz, opcje.w_czern, opcje.w_biel);
        if (opcje.konturowanie)
            kontur(&obraz);
        if (opcje.rozm_x)
            rozmywaniePoz(&obraz);
        if (opcje.rozm_y)
            rozmywaniePion(&obraz);
        if (opcje.roz_histo)
            rozciaganieHisto(&obraz);

        zapisz(opcje.plik_wy, &obraz);
        fclose(opcje.plik_wy);
    }
    else
    {
        
    }

    /* Zwalnianie pamięci przypisanej do tablicy */
    for (int i = 0; i < obraz.wymy; i++)
    {
        free(obraz.piksele[i]);
    }
    free(obraz.piksele);

    /* Wyswietlenie poprawnie wczytanego obrazu zewnetrznym programem */
    /*if (odczytano != 0)
        wyswietl(nazwa);*/

    return odczytano;
}