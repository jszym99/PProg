#include <stdio.h>
#include <stdlib.h>

void allocate (int *(**tablica), int *size)
{
    //printf("tab=%p ", (void *)tablica);

    *tablica = malloc (*size * sizeof(int *));
    printf("Tutaj");
    for(int i = 0; i < *size; i++)
    {
        //printf("Tutaj");
        (*tablica)[i] = malloc (*size * sizeof(int));
    }

    for(int i = 0; i < *size; i++)
    {
        for(int j = 0; j < *size; j++)
        {
            (*tablica)[i][j] = i+j;
        }
    }

    
     for(int i = 0; i < *size; i++)
    {
        for(int j = 0; j < *size; j++)
        {
             printf("%d ", (*tablica)[i][j]);
        }
        printf("\n");
    }

}

int main ()
{
    int **tab = NULL;
    int size = 10;

    //printf("tab=%p ", (void *)&tab);

    allocate(&tab, &size);
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
             printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    

    free (tab);
    return 0;
}