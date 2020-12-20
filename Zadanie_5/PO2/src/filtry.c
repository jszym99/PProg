#include <stdio.h>
#include <stdlib.h>
#include "filtry.h"

int negatyw (int *(**obraz_odwr), int *wymx, int *wymy, int *skala)
{
    for (int i = 0; i < *wymy; i++)
    {
        for (int j = 0; j < *wymx; j++)
        {
            (*obraz_odwr)[i][j] = (*skala) - (*obraz_odwr)[i][j];
        }
    }

    return 0;
}