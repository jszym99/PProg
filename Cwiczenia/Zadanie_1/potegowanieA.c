    #include <stdio.h>
    #include <stdlib.h>

    int main ()
    {
        int x, n, pow;
        printf("Podaj liczbe x\n");
        scanf("%d", &x);
        
        printf("Podaj potege n\n");
        scanf("%d", &n);

        pow = x; //Przypisanie pierwszej potęgi x

        if(n == 0) //Jeśli potęga jest zerowa wynik będzie 1 niezależnie od podstawy potęgi
            pow = 1;
        else if(x != 0) //Obliczanie pitęgi z użyciem mnożenia
        {
            for(int i = 1; i < abs(n); i++) //Mnożenien każdej poprzedniej potęgi przez x n razy zaczynając od x^1
                pow *= x;

        }
        if(n<0) //Wyświetlanie ułamka jeśli potęga n jest ujemna
            printf("%d^(%d) = 1/%d", x, n, pow);
        else
            printf("%d^%d = %d", x, n, pow);
        return 0;
    }