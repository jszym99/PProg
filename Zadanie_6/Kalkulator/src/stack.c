#include <stdio.h>
#include <stdlib.h>

//stack node structure
struct node
{
    int data;
    struct node* next;
};

//initiate the stack
void init(struct node* head)
{
    head = NULL;
}

//push element into the stack
struct node* push(struct node* head, int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("Nie udalo sie przypisac pamieci");
        exit(0);
    }
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

//take an element from the stack
struct node* pop(struct node *head,int *element)
{
    struct node* tmp = head;
    *element = head->data;
    head = head->next;
    free(tmp);
    return head;
}

//returns zero if stack is empty
int empty(struct node* head)
{
    if(head == NULL)
        return 1;
    else
        return 0;
}
