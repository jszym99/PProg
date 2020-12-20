#include <stdio.h>
#include <stdlib.h>
#include "filtry.h"

int negatyw (t_obraz *obraz_odwr)
{
    for (int i = 0; i < obraz_odwr->wymy; i++)
    {
        for (int j = 0; j < obraz_odwr->wymx; j++)
        {
            obraz_odwr->piksele[i][j] = (obraz_odwr->odcienie) - obraz_odwr->piksele[i][j];
        }
    }

    return 0;
}

int progowanie(t_obraz *obraz_prog, int prog)
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

    return 0;
}

int polProgowanieBieli(t_obraz *obraz_prog, int prog)
{
    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < obraz_prog->wymx; j++)
        {
            if(obraz_prog->piksele[i][j] <= prog)
                obraz_prog->piksele[i][j] = 0;
        }
    }

    return 0;
}

int polProgowanieCzerni(t_obraz *obraz_prog, int prog)
{
    for (int i = 0; i < obraz_prog->wymy; i++)
    {
        for (int j = 0; j < obraz_prog->wymx; j++)
        {
            if(obraz_prog->piksele[i][j] > prog)
                obraz_prog->piksele[i][j] = obraz_prog->odcienie;
        }
    }

    return 0;
}
