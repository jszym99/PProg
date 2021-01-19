#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

//stack node structure
struct node
{
    int data;
    struct node* next;
};

/************************************************************************************
 * Function checking if stack is empty
 *
 * \param[in] head element on top of the stack
 * \return 1 if stack is empty 0 if not empty
 ************************************************************************************/
int empty(struct node*);


/************************************************************************************
 * Function pushing new element into the stack
 *
 * \param[in] head element on top of the stack
 * \param[in] data data to place on top of the stack
 * \return head - element on top of the stack
 ************************************************************************************/
struct node* push(struct node*,int );

/************************************************************************************
 * Function taking top element from the stack
 *
 * \param[in] head element on top of the stack
 * \param[in] element variable to pass data from top of the stack
 * \param[out] element variable to pass data from top of the stack
 * \return head - element on top of the stack
 ************************************************************************************/
struct node* pop(struct node*,int*);

/************************************************************************************
 * Function initializing empty stack
 *
 * \param[in] head element on top of the stack
 ************************************************************************************/
void init(struct node*);

/************************************************************************************
 * Function displays full stack content
 *
 * \param[in] head element on top of the stack
 ************************************************************************************/
void display(struct node*);

/************************************************************************************
 * Function displays top of the stack
 *
 * \param[in] head element on top of the stack
 ************************************************************************************/
void top(struct node*);

#endif // LINKEDSTACK_H_INCLUDED