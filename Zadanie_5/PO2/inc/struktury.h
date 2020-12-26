#ifndef STRUKTURY_H
#define STRUKTURY_H

/* typ do przechowywania obrazów monochoromatycznych */
typedef struct {
int wymx, wymy, odcienie;
int **piksele;
} t_obraz;

/* strukura do zapamietywania opcji podanych w wywolaniu programu */
typedef struct
{
  FILE *plik_we, *plik_wy;                             /* uchwyty do pliku wej. i wyj. */
  int negatyw, progowanie, pol_prog_biel, pol_prog_czern,gamma,zmiana_poz, konturowanie, rozm_x, rozm_y, roz_histo, wyswietlenie; /* opcje */
  int w_progu;                                         /* wartosc progu dla opcji progowanie */
  float w_gamma;
  int w_czern, w_biel;
} t_opcje;

#endif
