    #include <stdio.h>
    #include <math.h>

    int main ()
    {
        float a, b, c, delta;


    //Test 1 a = 1, b = 4, c = 3
        a = 1;
        b = 4;
        c = 3;

        printf("\nTest 1\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
        delta = (b*b)-4.0*(a*c);
        printf("Delta = %f\n", delta);

        if(delta == 0)
        {
            float x = -b/(a*2);
            printf("x = %f\n", x);
        }
        else if(delta > 0)
        {
            printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
            printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
        }
        else
            printf("Brak rozwiazan rzerczywistych\n");
        }
        

    //Test 2 a = 0, b = 4, c = 3

        a = 0;
        b = 4;
        c = 3;

        printf("\nTest 2\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
        delta = (b*b)-4.0*(a*c);
        printf("Delta = %f\n", delta);

        if(delta == 0)
        {
            float x = -b/(a*2);
            printf("x = %f\n", x);
        }
        else if(delta > 0)
        {
            printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
            printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
        }
        else
            printf("Brak rozwiazan rzerczywistych\n");
        }

    //Test 3 a = 0, b = 0, c = 3

        a = 0;
        b = 0;
        c = 3;

        printf("\nTest 3\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniemjest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
            delta = (b*b)-4.0*(a*c);
            printf("Delta = %f\n", delta);

            if(delta == 0)
            {
                float x = -b/(a*2);
                printf("x = %f\n", x);
            }
            else if(delta > 0)
            {
                printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
                printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
            }
            else
                printf("Brak rozwiazan rzerczywistych\n");
        }


    //Test 4 a = 1, b = 0, c = 3
        a = 1;
        b = 0;
        c = 3;

        printf("\nTest 4\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
        delta = (b*b)-4.0*(a*c);
        printf("Delta = %f\n", delta);

        if(delta == 0)
        {
            float x = -b/(a*2);
            printf("x = %f\n", x);
        }
        else if(delta > 0)
        {
            printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
            printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
        }
        else
            printf("Brak rozwiazan rzerczywistych\n");
        }

    //Test 5 a = 1, b = 4, c = 4
        a = 1;
        b = 4;
        c = 4;

        printf("\nTest 5\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
        delta = (b*b)-4.0*(a*c);
        printf("Delta = %f\n", delta);

        if(delta == 0)
        {
            float x = -b/(a*2);
            printf("x = %f\n", x);
        }
        else if(delta > 0)
        {
            printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
            printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
        }
        else
            printf("Brak rozwiazan rzerczywistych\n");
        }


    //Test 6 a = 0, b = 0, c = 0;    
        a = 0;
        b = 0;
        c = 0;

        printf("\nTest 6\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
            delta = (b*b)-4.0*(a*c);
            printf("Delta = %f\n", delta);

            if(delta == 0)
            {
                float x = -b/(a*2);
                printf("x = %f\n", x);
            }
            else if(delta > 0)
            {
                printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
                printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
            }
            else
                printf("Brak rozwiazan rzerczywistych\n");
        }

    //Test 7 a = 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009, b = 4, c = 3;    
        a = 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009;
        b = 4;
        c = 3;

        printf("\nTest 7\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
            delta = (b*b)-4.0*(a*c);
            printf("Delta = %f\n", delta);

            if(delta == 0)
            {
                float x = -b/(a*2);
                printf("x = %f\n", x);
            }
            else if(delta > 0)
            {
                printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
                printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
            }
            else
                printf("Brak rozwiazan rzerczywistych\n");
        }

    
    //Test 8 a = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999, b = 4, c = -3;    
        a = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999;
        b = 4;
        c = -3;

        printf("\nTest 8\na = %f, b = %f, c = %f\n", a, b, c);

        if(a == 0.0) //równanie nie jest kwadratowe
        {
            if(b != 0.0)
                printf("To jest rownanie liniowe. x = %f\n", -c/b);
            else if(c == 0.0)
                printf("Rozwiazaniem jest dowoly x\n");
            else
                printf("Brak rozwiazan\ny = %f\n", c);
        }
        else
        {
            delta = (b*b)-4.0*(a*c);
            printf("Delta = %f\n", delta);

            if(delta == 0)
            {
                float x = -b/(a*2);
                printf("x = %f\n", x);
            }
            else if(delta > 0)
            {
                printf("x1 = %f\n", (-b+sqrt(delta))/(2*a));
                printf("x2 = %f\n", (-b-sqrt(delta))/(2*a));            
            }
            else
                printf("Brak rozwiazan rzerczywistych\n");
        }

        return 0;
    }