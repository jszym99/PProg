    #include <stdio.h>

    int main ()
    {
        int x = 0, n = 0, pow = 0;
        printf("Podaj liczbe x\n");
        scanf("%d", &x);
        printf("Potege n\n");
        scanf("%d", &n);
        printf("x = %d\n", x);
        printf("n = %d\n", n);

        pow = x;

        if (x == 0)
            pow = 0;
        else if(n == 0)
            pow = 1;
        else if(n == 1)
            pow = x;
        else
        {
            for(int i = 0; i < n-1; i++)
                pow *= x;
        }
        
        printf("%d^%d = %d", x, n, pow);

        return 0;
    }