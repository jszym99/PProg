#ifndef FILTRY_H
#define FILTRY_H

#include"struktury.h"

/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy
 *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM
 * \param[out] obraz_pgm struktura, do ktorej zostanie wczytany obraz
 * \return liczba wczytanych pikseli
 ************************************************************************************/
int czytaj (FILE *, t_obraz *);

/************************************************************************************
 * Funkcja zapisuje przetworzony obraz z tablicy do pliku
 * \param[in] plik_wy uchwyt do pliku w którym zostanie zapisany obraz
 * \param[in] obraz_zapisz struktura z przetworzonym obrazem do zapisu
 * **********************************************************************************/
void zapisz (FILE *, t_obraz *);

#endif