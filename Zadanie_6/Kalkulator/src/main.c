#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct node* head = NULL;

    init(head);

    for(int i = 0; i < 5; i++)
    {
        head = push(head, i);
    }

    while (head != NULL)
    {
        int element;
        head = pop(head, &element);
        printf("%d ", element);
    }
    

    return 0;
}