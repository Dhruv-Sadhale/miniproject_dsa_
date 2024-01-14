#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

typedef struct node{
	int val;
	struct node* next;
	struct node* prev;
}node;
typedef struct list{
	node* front;
	node* rear;
}list;
//beginning of stack 
typedef struct sll{
	char data;
	struct sll *next;
}sll;



typedef struct stack{
	sll* l;
	sll *top;
}stack;

void init_list(sll **l);
void insert(sll** l,char d);
void append(sll** ptr,char d);
void deletel(sll **l);
int isemptyl(sll* l);
void init_stack(stack *s);
int isempty(stack s);
void push(stack *s,char d);
char peek(stack s);
char pop(stack* s);
void display(stack s);

void init(list* ptr);
void insertRight(list* ptr,int val);
void insertLeft(list* ptr, int val);
void displayLR(list* ptr);
int isemptylist(list *ptr);
void displayRL(list* ptr);
void deleteRight(list* ptr);
void deleteLeft(list* ptr);
void delete(list* ptr);


int isgreater(list* ptr1, list* ptr2);
void subtraction(list* ptr1, list* ptr2,list *diff);
void addition(list* ptr1,list* ptr2,list* sum);
void  multiplication(list* ptr1, list* ptr2,list* result);
void division(list* ptr1, list*ptr2, list* quotient);
int precedence(char c);
void calculate(list* ptr1, list* ptr2, char op,list* result);
void builder();

