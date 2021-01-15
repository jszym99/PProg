#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

int empty(struct node*);
struct node* push(struct node*,int );
struct node* pop(struct node*,int*);
void init(struct node*);
#endif // LINKEDSTACK_H_INCLUDED