#include "binary_calculator_612203043.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

void init_list(sll **l){
   *l = NULL;
    return;
}

void insert(sll** l,char d){
    sll *nn;
    nn = (sll*)malloc(sizeof(sll));
	if(nn){
		nn->data = d;
        nn->next = NULL;
	}
	else
	return;
    nn->next = *l;
    *l = nn;
    return;
}
void append(sll** ptr,char d){
	sll* nn=(sll*)malloc(sizeof(sll));
	if(nn){
		nn->data=d;
		nn->next=NULL;
	}
	else return;
	if(*ptr==NULL){
		*ptr=nn;
	}
	else{
		sll* p=*ptr;
		while(p->next){
			p=p->next;
		}
		p->next=nn;
	}return;
}
void deletel(sll **l){
  sll *p = *l;

  // if there are no nodes in Linked List can't delete
  if (!p)
      return ;


  *l = p->next;
  free(p);

    return;
}

int isemptyl(sll* l){
    if(!(l))
        return 1;
    else
        return 0;
}


void init_stack(stack *s){
    init_list(&(s->l));
    s->top=NULL;
    return;
}
int isempty(stack s){
    if(s.top==NULL)
        return 1;
    else
        return 0;
}
void push(stack *s,char d){
    insert(&(s->l),d);
    sll *p=s->l;
    s->top=s->l;
    return;
}
char peek(stack s){
    if(isempty(s))
        return CHAR_MAX;
    else
        return ((s.top)->data);
}
char pop(stack* s){
    if(isempty(*s))
        return CHAR_MAX;
    int j= peek(*s);
    deletel(&(s->l));
    s->top=s->l;
    return j;
}
void display(stack s){ 
    if(isempty(s)){
        printf("Stack is empty");
        return;
    }
    printf("[");
    sll *p=s.top;
    while(p){
        printf("%c",p->data);
        p=p->next;
       
    }
    printf("]\n");
    return;
}

//stack definitions end here

//doubly linked list definitions begin here
void init(list* ptr){
	ptr->front=NULL;
	ptr->rear=NULL;
}

void insertRight(list* ptr,int val){
	node* nn=(node*)malloc(sizeof(node));
	if(nn){
		nn->val=val;
		nn->next=NULL;
		nn->prev=NULL;
	}
	else
		return;
	if(ptr->front==NULL){
		ptr->front=nn;
		ptr->rear=nn;
		return;
	}
	ptr->rear->next=nn;
	nn->prev=ptr->rear;
	ptr->rear=nn;
	return;
}
void insertLeft(list* ptr, int val){
	node* nn=(node*)malloc(sizeof(node));
	if(nn){
		nn->val=val;
		nn->next=NULL;
		nn->prev=NULL;
	}
	else
		return;
	if(ptr->front==NULL){
		ptr->front=nn;
		ptr->rear=nn;
		return;
	}
	ptr->front->prev=nn;
	nn->next=ptr->front;
	ptr->front=nn;
	return;
}
void displayLR(list* ptr){
	if(ptr->front==NULL){
		return;
	}
	node* p=ptr->front;
	while(p){
		printf("%d",p->val);
		p=p->next;
	}
	printf("\n");
	return;
}
int isemptylist(list *ptr){
	if (ptr->front==NULL){
		return 1;
	return 0;
}
}
void displayRL(list* ptr){
	if(ptr->rear==NULL){
		return;
	}
	node* p=ptr->rear;
	while(p){
		printf("%d",p->val);
		p=p->prev;
	}
	printf("\n");
	return;
}
void deleteRight(list* ptr){
	if(isemptylist(ptr)){
		return;
	}	
	node* p=ptr->rear;
	ptr->rear=ptr->rear->prev;
	if(ptr->rear!=NULL){
		ptr->rear->next=NULL;
	}
	free(p);
}
void deleteLeft(list* ptr){
	if(isemptylist(ptr)){
		return;
	}	
	node* p=ptr->front;
	ptr->front=ptr->front->next;
	if(ptr->front!=NULL){
		ptr->front->prev=NULL;
	}
	free(p);
}
void delete(list* ptr){
	if(isemptylist(ptr)){
		return;
	}
	node* p=ptr->front;
	node* q=ptr->front;
	while(q){
		p=q;
		q=q->next;
		free(p);
	}
	ptr=NULL;
	return;
}
int isgreater(list* ptr1, list* ptr2){
	//returns 1 if ptr1 > ptr2
	//returns 0 if ptr1=ptr2
	//returns -1 if ptr1<ptr2
 	node* p1=(ptr1)->front;
	node* p2=(ptr2)->front;
	int len1=0;
	int len2=0;
	node *q1;
	node *q2;
	//removing all leading zeros
	while(p1 && p1->val==0 ){
		q1=p1;
		ptr1->front=ptr1->front->next;
		p1=p1->next;
		free(q1);

	}
	if(!p1){
	init(ptr1);
		insertLeft(ptr1,0);
	}
	while(p2 && p2->val==0 ){
	q2=p2;
		ptr2->front=ptr2->front->next;
		p2=p2->next;
		free(q2);

	}
	if(!p2){
	init(ptr2);
		insertLeft(ptr2,0);
	}
	p1=(ptr1)->front;
	p2=(ptr2)->front;
	//counting the number of digits in each number
	while(p1){
		len1++;
		p1=p1->next;
	}
	while(p2){
		len2++;
		p2=p2->next;
	}
	
	if(len1>len2){
		return 1;
	}
	else if(len2>len1){
		return -1;
	}
	else{
	//final checking of which number is greater
		p1=(ptr1)->front;
		p2=(ptr2)->front;
		while(p1 && p2){
			if(p1->val >p2->val){
				return 1;
			}
			else if(p1->val <p2->val){
				return -1;
			}
			p1=p1->next;
			p2=p2->next;
		}
	p1=NULL;
	p2=NULL;
	q1=NULL;
	q2=NULL;
	free(p1);
	free(p2);
	free(q1);
	free(q2);
		return 0;
	}
	
}

void subtraction(list* ptr1, list* ptr2,list *diff){
	int now,num;
	//now variable represents the new number from which we divide after considering the borrow from the previous digit
	//todo variable is if the current number is 0 and thus the next digits must also be changed
	// num is to temporarily store the values
	//change is to represent if borrow is required for the next bit of the larger number
	int change=0, todo=0;
	node* p1;
	node* p2;
	if(isgreater(ptr1,ptr2)==0){
		insertLeft(diff,0);
		return;
		}
	else if(isgreater(ptr1,ptr2)==1){
	 p1=(ptr1)->rear;
	p2=(ptr2)->rear;
	}
	else{
	 p2=(ptr1)->rear;
	p1=(ptr2)->rear;
	}
	while(p1 && p2){
		if(change==1 || todo==1){
			if(p1->val!=0){
				now=p1->val-1;
				todo=0;
			}
			else{
				now=9;
				todo=1;
			}
		}
		else{
			now=p1->val;
		}
		if(now >=p2->val){
			insertLeft(diff,now-p2->val);
			change=0;
		}
		else{
			num=10+now;
			insertLeft(diff,num-p2->val);
			change=1;
		}
		p1=p1->prev;
		p2=p2->prev;
	}
	while(p1){
		if(change==1 || todo==1){
			if(p1->val!=0){
				now=p1->val-1;
				insertLeft(diff,now);
				change=0;
				todo=0;
			}
			else{
				now=9;
				insertLeft(diff,now);
				todo=1;
			}
		}
		else{
			now=p1->val;
			insertLeft(diff,now);
			change=0;
		}
		p1=p1->prev;
	}
	while(p2){
		int imaginary0=0;
			if(change==1 || todo==1){
			if(imaginary0!=0){
				now=p1->val-1;
				todo=0;
			}
			else{
				now=9;
				todo=1;
			}
		}
		else{
			now=imaginary0;
		}
		if(now >=p2->val){
			insertLeft(diff,now-p2->val);
			change=0;
		}
		else{
			num=10+now;
			insertLeft(diff,num-p2->val);
			change=1;
		}
		
		p2=p2->prev;
	}
	free(p1);
	free(p2);
	
	node *q1;
	node* pp=diff->front;
	while(pp && pp->val==0 ){
		q1=pp;
		diff->front=diff->front->next;
		pp=pp->next;
		free(q1);

	}
	if(!pp){
	init(diff);
		insertLeft(diff,0);
	}
	q1=NULL;
	pp=NULL;
	free(q1);
	free(pp);
}		
void addition(list* ptr1,list* ptr2,list* sum){
	int k=0;
	int num;
	node* p1=(ptr1)->rear;
	node* p2=(ptr2)->rear;
	while(p1 && p2){
		
		if(p1->val+p2->val+k >9){
			num=(p1->val+p2->val+k)%10;	
			insertLeft(sum,num);
			k=1;
		}
		else{
			num=p1->val+p2->val+k;
			insertLeft(sum,num);
			k=0;
		}
		p1=p1->prev;
		p2=p2->prev;
	}
	while(p1){
		num=p1->val+k;
		if (num>9){
			insertLeft(sum, 0);
			k=1;
		}
		else{
			insertLeft(sum,num);
			k=0;
		}
		p1=p1->prev;
	}
	while(p2){
		num=p2->val+k;
		if (num>9){
			insertLeft(sum, 0);
			k=1;
		}
		else{
			insertLeft(sum,num);
			k=0;
		}
		p2=p2->prev;
	}
	if(k==1){
		insertLeft(sum,1);
	}
	p1=NULL;
	p2=NULL;
	free(p1);
	free(p2);

}

void  multiplication(list* ptr1, list* ptr2,list* result){
	node* p1=(ptr1)->front;
	node* p2=(ptr2)->front;
	//first we check for the bigger number
	int len1=0;
	int len2=0;
	while(p1){
		len1++;
		p1=p1->next;
	}
	while(p2){
		len2++;
		p2=p2->next;
	}
	if(len1>len2){
		p1=(ptr1)->rear;
		p2=(ptr2)->rear;
	}
	else if(len2>len1){
		p1=(ptr2)->rear;
		p2=(ptr1)->rear;
	}
	else{
		int flag=0;
		p1=(ptr1)->front;
		p2=(ptr2)->front;
		while(p1 && p2){
			if(p1->val >p2->val){
				p1=(ptr1)->rear;
				p2=(ptr2)->rear;
				flag=1;
				break;
			}
			else if(p1->val <p2->val){
				p1=(ptr2)->rear;
				p2=(ptr1)->rear;
				flag=1;
				break;
			}
			p1=p1->next;
			p2=p2->next;
		}
		if (flag==0){
			p1=(ptr1)->rear;
			p2=(ptr2)->rear;
		}
	}
	//now we perform the multiplication algorithm
	node* least=p1;
    int i = 0;
    int carry = 0;
    int num;
    int size=(len2>len1)? len1:len2;
    list** level=(list**)malloc(sizeof(list*)*size);
    list** sum=(list**)malloc(sizeof(list*)*(size+1));
    sum[0]=(list*)malloc(sizeof(list));
    init(sum[0]);
    insertLeft(sum[0],0);
    while (p2) {
        p1 = least;
        carry = 0;
        level[i]=(list*)malloc(sizeof(list));
	sum[i+1]=(list*)malloc(sizeof(list));
	init(level[i]);
	init(sum[i+1]);
        while (p1) {
            num = ((p1->val * p2->val) + carry) % 10;
            carry = ((p1->val * p2->val) + carry) / 10;
            insertLeft(level[i], num);
            
       
            p1 = p1->prev;
        }

        if (carry != 0) {
            insertLeft(level[i], carry);
        }

        int z = i;
        while (z >= 1) {
            insertRight(level[i], 0);
            z--;
        }
        addition(sum[i], level[i],sum[i+1]);
        i++;
        p2 = p2->prev;
    }
	node* transfer=sum[i]->front;
	while(transfer){
		insertRight(result,transfer->val);
		transfer=transfer->next;
	}
	
	
	p1=NULL;
	free(p1);
	p2=NULL;
	free(p2);
	least=NULL;
	free(least);
	transfer=NULL;
	free(transfer);
	for(int i=0;i<size;i++){
		free(level[i]);
	}
	for(int i=0;i<size+1;i++){
		free(sum[i]);
	}

}


void division(list* ptr1, list*ptr2, list* quotient){
	if(ptr2->front->val==0){
		printf("Error, cannot divide by zero\n");
		exit(0);
	}
	node* p1=ptr1->front;
		list* rem=NULL;
		p1=ptr1->front;
		list* temp=(list*)malloc(sizeof(list));
		init(temp);
		
	while(p1){
			insertRight(temp,p1->val);
			p1=p1->next;
		if(isgreater(ptr2,temp)==1){
			insertRight(quotient,0);
		}
		else{
			int i=0;
			list *mul;
			list* I=(list*)malloc(sizeof(list));
			init(I);
			insertLeft(I,i);
			while(i<=10){
					mul=(list*)malloc(sizeof(list));
					init(mul);
					I->front->val=i;
					multiplication(ptr2,I,mul);
					int yes=isgreater(mul,temp);
				if(yes==-1){
					
					
				}
				else if(yes==0){
					break;
				}
				else{
					i=i-1;
					break;
				}
				i++;
			}
			free(I);
			free(mul);
			insertRight(quotient,i);
			rem=(list*)malloc(sizeof(list));
			init(rem);
			
			
			I=(list*)malloc(sizeof(list));
			init(I);
			insertLeft(I,i);
			mul=(list*)malloc(sizeof(list));
			init(mul);
			multiplication(ptr2,I,mul);
			
			subtraction(temp,mul,rem);
			free(mul);
			free(I);
			
			if(p1==NULL) break;
			if(p1!=NULL){
				free(temp);
				temp=(list*)malloc(sizeof(list));
				init(temp);
				node* p=rem->front;
				while(p){
					insertRight(temp,p->val);
					p=p->next;
				}
				free(rem);
				
			}
			
		}
	}
	
	node *q1;
	node* pp=quotient->front;
	while(pp && pp->val==0 ){
		q1=pp;
		quotient->front=quotient->front->next;
		pp=pp->next;
		free(q1);

	}
	if(!pp){
	init(quotient);
		insertLeft(quotient,0);
	}
	q1=NULL;
	pp=NULL;
	free(q1);
	free(pp);
}


int precedence(char c){
    if(c == '+')
        return 10;
    else if(c == '-')
        return 10;
    else if(c == '*')
        return 20;
    else if(c == '/')
        return 20;
    else if(c == '(')
        return 5;
    return 0;
}

void calculate(list* ptr1, list* ptr2, char op,list* result){
	switch(op){
		case '+': addition(ptr1,ptr2,result);
			 break;
		case '-': subtraction(ptr1,ptr2,result);
			break;
		case '*': multiplication(ptr1,ptr2,result);
			break;
		case '/':division(ptr1,ptr2,result);	
			break;
		default: printf("invalid\n");
			break;
	}
	
}	

	

void builder(){

    sll* infix;
    init_list(&infix);
    int entry;
    printf("--------BINARY CALCULATOR---------\n");
    printf("Enter your expression:\n");
    while((entry=getchar())!=EOF){
    	append(&infix,entry);
    }
    stack s;
    init_stack(&s);
    sll* postfix;
    init_list(&postfix);
    
    stack bucket;
    init_stack(&bucket);
    char c;
    append(&postfix,' ');
    while(infix){
            c = infix->data;
            if(isdigit(c)){
               append(&postfix, c );
               if(infix->next==NULL || !isdigit(infix->next->data))
                    append(&postfix, ' ');
            }
            else if( c == '(')
                push(&s,'(');
            else if(c == ')'){
                    while(!isempty(s) && peek(s)!= '('){
                          append(&postfix , pop(&s));
                          append(&postfix , ' ');
                    }
                    if(peek(s) == '(')
                        pop(&s);
            }
            else {
                    if( c == '+' || c =='-' || c == '*'|| c == '/') {
                        if(isempty(s))
                            push(&s, c);
                        else {
                            while(!isempty(s) && precedence(peek(s)) >= precedence(c)){
                          	append(&postfix , pop(&s));
                          	append(&postfix , ' ');
                            }
                            push(&s, c);
                        }
                    }
            }
       infix=infix->next;

    }
    
    while(!isempty(s)){
        append(&postfix , pop(&s));
        append(&postfix , ' ');
    }
    //now we do our final calculations
    	list *l1;
	list *l2;
	list *result;
	int l1m=0, l2m=0;
    while(postfix){
    	if(postfix->data=='+' || postfix->data=='-' ||postfix->data=='*' ||postfix->data=='/' ){
    		int space=0;
    		    l1=(list*)malloc(sizeof(list));
		l2=(list*)malloc(sizeof(list));
		result=(list*)malloc(sizeof(list));
    		init(l1);
    		init(l2);
    		init(result);
    		while(space!=3){
    			if(peek(bucket)==' '){
    				
    				space++;
    				if(space==3) break;
    				pop(&bucket);
    			}
    			else{
    				if(space==1){

    					if(peek(bucket)=='m'){
    					l2m=1;
    					pop(&bucket);
    					} else{
    					 l2m=0;
    					
    					insertLeft(l2,pop(&bucket)-'0');

    					}
    				}
    				else if(space==2){
					
    					if(peek(bucket)=='m'){

    					  pop(&bucket);


    					l1m=1;


    					} else {l1m=0;
    					insertLeft(l1,pop(&bucket)-'0');

    					}

    				}
    			}
    		}
    			if(postfix->data=='+' && l2m==1 && l1m==1){
    			calculate(l1,l2,postfix->data,result);
    			push(&bucket,'m');
    			//printf("Case 1\n");
    			}
    			else if(postfix->data=='+' && (((l2m==1 && l1m!=1) && isgreater(l1,l2)==1) || (l2m==0 && l1m==1 &&  isgreater(l1,l2)==-1))){
    			calculate(l1,l2,'-',result);
    		
    			//printf("Case 2\n");
    			}
    			else if(postfix->data=='+' && (((l2m==1 && l1m!=1) && isgreater(l1,l2)==-1) || (l2m==0 && l1m==1 && isgreater(l1,l2)==1))){
    			calculate(l1,l2,'-',result);
    			push(&bucket,'m');
    			//printf("Case 3\n");
    			}
    			else if(postfix->data=='+' && (l2m==1 || l1m==1 ) && isgreater(l1,l2)==0){
    			insertLeft(result,0);
    			//printf("Case 4\n");
    			}
    			else if(postfix->data=='+' && l2m==0 && l1m==0){
    			calculate(l1,l2,postfix->data,result);
    			//printf("Case 5\n");
    			//push(&bucket,'m');
    			}
    			else if(postfix->data=='-' && l2m==1 && l1m==1 && isgreater(l1,l2)==1){
    			calculate(l1,l2,'-',result);	
    			push(&bucket,'m');
    			//printf("Case 6\n");
    			}
    			else if(postfix->data=='-' && l2m==1 && l1m==1 && isgreater(l1,l2)==-1){
    			calculate(l1,l2,'-',result);	
    			//printf("Case 7\n");
    			}
    			else if(postfix->data=='-' && l2m==l1m && isgreater(l1,l2)==0){
    			    			insertLeft(result,0);
    			    			//printf("Case 8\n");
    			}
    			else if(postfix->data=='-' && l2m==0 && l1m==0 && isgreater(l1,l2)==1){
    			calculate(l1,l2,'-',result);	
    			//printf("Case 9\n");
    			}
    			else if(postfix->data=='-' && l1m==0 && l2m==0 && isgreater(l1,l2)==-1){
    			calculate(l1,l2,'-',result);	
    			push(&bucket,'m');
    			//printf("Case 10\n");
    			}
    			else if(postfix->data=='-' && l2m==1 && l1m==0 ){
    			calculate(l1,l2,'+',result);
    			//printf("Case 11\n");	
    			}
    			else if(postfix->data=='-' && l2m==0 && l1m==1 ){
    			calculate(l1,l2,'+',result);	
    			push(&bucket,'m');
    			//printf("Case 12\n");
    			}
    			else if(postfix->data=='*' && l1m==l2m){
    			calculate(l1,l2,'*',result);
    			//printf("Case 13\n");	
    			}
    			else if(postfix->data=='*' && (l1m==1 || l2m==1)){
    			
    			calculate(l1,l2,'*',result);	
    			//printf("BP\n");
    			push(&bucket,'m');
    			//printf("Case 14\n");	
    			}
   
    			else if(postfix->data=='/' && l1m==l2m){
    			calculate(l1,l2,'/',result);	
    			//printf("Case 15\n");
    			}
    			else if(postfix->data=='/' && (l1m==1 || l2m==1)){
    			calculate(l1,l2,'/',result);	
    			push(&bucket,'m');
    			//printf("Case 16\n");	
    			}
    			
    			//then we push the result back in 
    			node* p=result->front;
    			while(p){
    				push(&bucket,(char)((int)'0'+p->val));
    				p=p->next;
    			}
    			free(l1);
    			free(l2);
    			free(result);

    			
    	}
    	else{
    		push(&bucket,postfix->data);

    	}
    	postfix=postfix->next;
    }
    
    
	list* bd=(list*)malloc(sizeof(list));
	init(bd);
	while(!isempty(bucket)){
	if(peek(bucket)=='m'){
	bd->front->val=bd->front->val *(-1);
	pop(&bucket);}
	if(peek(bucket)==' '){
	pop(&bucket);
	}
	else
		insertLeft(bd,pop(&bucket)-'0');
	}
	printf("Answer:\n");
	displayLR(bd);
	free(bd);
	free(infix);
	free(postfix);
}


