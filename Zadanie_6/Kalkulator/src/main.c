#define EMPTY 1
#define NOT_INT 2
#define UNK_OPT 3
#define QUIT 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int getNum(struct node **head, long long *a, long long *b)
{
    int iTmp = 0;
    long long lTmp = 0;
    //pobieranie liczb ze stosu do wykonania obliczeń
    if (empty(*head))
        return EMPTY;
    else
        *head = pop(*head, &iTmp); //take a number form the top of the stack
    *b = iTmp;

    if (empty(*head))
    {
        *head = push(*head, *b);
        return EMPTY;
    }
    else
    {
        *head = pop(*head, &iTmp); //take a number form the top of the stack
        *a = iTmp;
        return 0;
    }
}

int operation(struct node **head, char operator)
{
    long long a, b, c = 0;
    int result = 0;

    //operations that DON'T require top two numbers from the stack
    switch (operator)
    {
    case 'P': //remove top number in the stack
    {
        if (empty(*head))
            return EMPTY;
        else
            *head = pop(*head, &result); //take a number form the top of the stack
        return 0;
    }
    case 'c': //clear the stack
    {
        while (!empty(*head))
        {
            *head = pop(*head, &result);
        }
        return 0;
    }
    case 'd': //duplicate top element in the stack
    {
        if (empty(*head))
            return EMPTY;
        else
        {
            *head = pop(*head, &result);
            *head = push(*head, result);
            *head = push(*head, result);
        }
        return 0;
    }
    case 'p': //print top element in the stack
    {
        if (empty(*head))
            return EMPTY;
        else
            top(*head);
        return 0;
    }
    case 'f': //print full stack
    {
        if (empty(*head))
            return EMPTY;
        else
            display(*head);
        return 0;
    }
    case 'q': //quit (stop the programm)
    {
        return QUIT;
    }
    case 'r': //reverse 2 top numbers in the stack
    {
        if (getNum(head, &a, &b))
            return EMPTY;
        else
        {
            *head = push(*head, b);
            *head = push(*head, a);
        }
        return 0;
    }
    case '+':
    {
        if (getNum(head, &a, &b))
            return EMPTY;
        else
            c = a + b;
        break;
    }
    case '-':
    {
        if (getNum(head, &a, &b))
            return EMPTY;
        else
            c = a - b;
        break;
    }
    case '*':
    {
        if (getNum(head, &a, &b))
            return EMPTY;
        else
            c = a * b;
        break;
    }
    case '/':
    {
        if (getNum(head, &a, &b))
            return EMPTY;
        else
            c = a / b;
        break;
    }
    default:
        return UNK_OPT; //unknown option
    }

    if (c <= INT_MAX && c >= INT_MIN) //jeśli mieści się w zmiennej typu int
    {
        result = c;
        *head = push(*head, result);
        top(*head);
    }
    else
    {
        *head = push(*head, a);
        *head = push(*head, b);
        return NOT_INT;
    }

    return 0;
}

int main()
{
    //element on top of the stack
    struct node *head = NULL;

    init(head);

    char inBuf[100];
    int flag = 0;

    while (flag != QUIT)
    {
        flag = 0;
        scanf("%s", &inBuf[0]);

        long long iTmp = 0;
        char cTmp = ' ';

        if (0 < sscanf(inBuf, "%lld", &iTmp))
            if (iTmp <= INT_MAX && iTmp >= INT_MIN) //jeśli mieści się w zmiennej typu int
                head = push(head, iTmp);
            else
                printf("Input value out of range of int (+/- %d)\n", INT_MAX);
        else if (0 < sscanf(inBuf, "%c", &cTmp))
        {
            if (flag = operation(&head, cTmp))
                printf("ERROR: %d\n", flag);

            switch (flag)
            {
            case EMPTY:
            {
                if(empty(head))
                    printf("Stack is mepty\n");
                else
                    printf("Not enough numbers on the stack");
                break;
            }
            case NOT_INT:
                printf("Calculation result out of range of int (+/- %d)\n");
                break;
            case UNK_OPT:
                printf("Unknown option.\nAvailable options:\nnumber\n+,-,*,/\nP-delete last number\nc-clear\nr-reverse\np-print\nf-full print\nq-quit\n");
                break;
            case QUIT:
            {
                cTmp = ' ';
                printf("Are you sure you want to quit? [y/n]\n");
                scanf("%c", &cTmp);
                if (cTmp == 'y' || cTmp == 'Y');
                else
                    flag = 0;
            }
            default:
                break;
            }
        }
    }

    return 0;
}