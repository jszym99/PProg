#ifndef FILTRY_H
#define FILTRY_H

#include"struktury.h"

/************************************************************************************
 * Funkcja wylicza negatyw obrazu
 *
 * \param[in] obraz_odwr struktura zawierajaca przetwarzany obraz
 * \param[out] obraz_odwr struktura, do ktorej zostaje zapisany negatyw
 ************************************************************************************/
void negatyw(t_obraz *);

/************************************************************************************
 * Funkcja wylicza próg orbazu
 *
 * \param[in] obraz_prog struktura zawierajaca przetwarzany obraz
 * \param[in] prog wartoś określająca próg czerni/bieli obrazu
 * \param[out] obraz_prog struktura, do ktorej zostaje zapisany progowany obraz
 ************************************************************************************/
void progowanie(t_obraz *, int);

/************************************************************************************
 * Funkcja wylicza prób bieli (poniżej progu zamiana szarości na biel)
 *
 * \param[in] obraz_prog struktura zawierajaca przetwarzany obraz
 * \param[in] prog_b wartoś określająca próg bieli obrazu
 * \param[out] obraz_prog struktura, do ktorej zostaje zapisany progowany obraz
 ************************************************************************************/
void polProgowanieBieli(t_obraz *, int);

/************************************************************************************
 * Funkcja wylicza prób czerni (powyżej progu zamiana szarości na czerń)
 *
 * \param[in] obraz_prog struktura zawierajaca przetwarzany obraz
 * \param[in] prog_c wartoś określająca próg czerni obrazu
 * \param[out] obraz_prog struktura, do ktorej zostaje zapisany progowany obraz
 ************************************************************************************/
void polProgowanieCzerni(t_obraz *, int);

/************************************************************************************
 * Funkcja wylicza korekcję gamma
 *
 * \param[in] obraz_gamma struktura zawierajaca przetwarzany obraz
 * \param[in] pGamma wartość parametru gamma
 * \param[out] obraz_gamma struktura, do ktorej zostaje zapisany przeskalowany obraz
 ************************************************************************************/
void korGamma(t_obraz *, float);

/************************************************************************************
 * Funkcja wylicza nowe poziomy czerni i bieli
 *
 * \param[in] obraz_gamma struktura zawierajaca przetwarzany obraz
 * \param[in] czern wartość poziomu czerni
 * \param[in] biel wartość poziomu bieli
 * \param[out] obraz_gamma struktura, do ktorej zostaje zapisany z nowymi poziomami czerni i bieli
 ************************************************************************************/
void zmianaPoz(t_obraz *, int, int);

/************************************************************************************
 * Funkcja wylicza kontury obiektów metodą gradientową
 *
 * \param[in] obraz_kontur struktura zawierajaca przetwarzany obraz
 * \param[out] obraz_kontur struktura, do ktorej zostaje zapisany wykonturowany obraz
 ************************************************************************************/
void kontur(t_obraz *);

/************************************************************************************
 * Funkcja wylicza rozmycie poziome obrazu
 *
 * \param[in] obraz_rozmx struktura zawierajaca przetwarzany obraz
 * \param[out] obraz_rozmx struktura, do ktorej zostaje zapisany rozmyty obraz
 ************************************************************************************/
void rozmywaniePoz(t_obraz *);

/************************************************************************************
 * Funkcja wylicza rozmycie pionowe obrazu
 *
 * \param[in] obraz_rozmy struktura zawierajaca przetwarzany obraz
 * \param[out] obraz_rozmy struktura, do ktorej zostaje zapisany rozmyty obraz
 ************************************************************************************/
void rozmywaniePion(t_obraz *);

/************************************************************************************
 * Funkcja wylicza rozciągnięcie histogramu na cały zakres szarości
 *
 * \param[in] obraz_histo struktura zawierajaca przetwarzany obraz
 * \param[out] obraz_histo struktura, do ktorej zostaje zapisany rozciągnięty obraz
 ************************************************************************************/
void rozciaganieHisto(t_obraz *);

/************************************************************************************
 * Funkcja zamienia obraz kolorowy na czarno-biały
 *
 * \param[in] obraz_szary struktura zawierajaca przetwarzany obraz
 * \param[out] obraz_szary struktura, do ktorej zostaje zapisany czarno-biały obraz
 ************************************************************************************/
void szarosci(t_obraz *);

#endif