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
/*
void init_stack(stack *s);
void init_list(list *l);
int isempty(stack s);
void push(stack *s,int d);
int pop(stack *s);
int peek(stack s);
void insert(list *l,int d);
void deletel(list *l);
int isemptyl(list l);
void display(stack s);
*/
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
    printf("[ ");
    sll *p=s.top;
    while(p){
    	//if(p->data!=' ')
        printf("%c",p->data);
       // if(p->data=='m'){
        //printf("%c",'-');
        p=p->next;
       
    }
    printf("]\n");
    return;
}

//stack definitions end here
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
		//printf("Empty List\n");
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
		//printf("Empty List\n");
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
/*void deleteList(list* ptr) {
    if (!ptr) return;
    node* current = ptr->front;
    node* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    ptr->front = ptr->rear = NULL; // Reset the list pointers
}*/

/*void deleteStack(stack* s) {
    deleteList(s->l);
    s->top = NULL;
}*/
int isgreater(list* ptr1, list* ptr2){
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
		return 1;
	}
	else if(len2>len1){
		return -1;
	}
	else{
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
		return 0;
	}
}
void subtraction(list* ptr1, list* ptr2,list *diff){
	int now,num;
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
	//list diff;
	//init(&diff);
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
	//displayLR(diff);
	while(diff->front->val==0){
		deleteLeft(diff);
		diff->front=diff->front->next;
	}
}	
		
		
void addition(list* ptr1,list* ptr2,list* sum){
	//printf("enters addition function\n");
	int k=0;
	int num;
	node* p1=(ptr1)->rear;
	node* p2=(ptr2)->rear;
	//list sum;
	//init(&sum);
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
	//list* ret=&sum;
	displayLR(sum);
	//return ret;

}

void  multiplication(list* ptr1, list* ptr2,list* result){
//printf("enters multilication func\n");
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
	//printf("%d %d %d %d\n", len1, len2, p1->val, p2->val); //correct till here
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
   // displayLR(sum[0]);
    while (p2) {
        p1 = least;
        carry = 0;
        level[i]=(list*)malloc(sizeof(list));
	sum[i+1]=(list*)malloc(sizeof(list));
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
      //  printf("for level %d: ",i);
        //displayLR(level[i]);
        addition(sum[i], level[i],sum[i+1]);
       // free(sum[i]);
        //free(level[i]);
        i++;
        p2 = p2->prev;
    }
    	//printf("Result of multiplication operation\n");
    	  //  displayLR(sum[i]);
	node* transfer=sum[i]->front;
	while(transfer){
		insertRight(result,transfer->val);
		transfer=transfer->next;
	}
	//free(*sum);
	//free(*level);
	//free(*sum);

}

void division(list* ptr1, list*ptr2, list* quotient){
	node* p1=ptr1->front;
	int i=1;
	int z=0;
	//list* temp=NULL;
		list* rem=NULL;
		p1=ptr1->front;
		list* temp=(list*)malloc(sizeof(list));
		init(temp);
		
	while(p1){
	
		//p1=ptr1->front;
		
		
		
			insertRight(temp,p1->val);
			p1=p1->next;
		if(isgreater(ptr2,temp)){
			insertRight(quotient,0);
			
		}
		else{
			
			insertRight(quotient,1);
			 rem=(list*)malloc(sizeof(list));
			init(rem);
			subtraction(temp,ptr2,rem);//yet to be designed
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
				rem=NULL;
			}
		}
	}
	displayLR(quotient);
	if(rem!=NULL)
	displayLR(rem);
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
    else if(c == '%')
        return 20;
    else if(c == '^')
        return 30;
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
		case '/': division(ptr1,ptr2,result);
			break;
		default: printf("invalid\n");
			break;
	}
	//printf("Final result is:\n");
	
}	

	

 int main(){

    sll* infix;//E
    init_list(&infix);
    int entry;
    printf("Enter:\n");
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
   // printf("%c",infix->data);
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
                  	//printf("%c, ",postfix->data);
       infix=infix->next;

    }
    
	//display(s);
    while(!isempty(s)){
        append(&postfix , pop(&s));
        append(&postfix , ' ');
    }
   // printf("hello??\n");
    //to display postfix
    sll* fornow=postfix;
    while(fornow){
    	printf("%c", fornow->data);
    	fornow=fornow->next;
    }
    free(fornow);
    printf("\n");
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
    		//printf("is empty? %d\n",isempty(bucket));
    		//printf("how many times here?\n");
    		while(space!=3){
    			if(peek(bucket)==' '){
    				//printf("bp1\n");
    				space++;
    				if(space==3) break;
    				pop(&bucket);
    			}
    			else{
    				if(space==1){
    				//printf("bp2\n");
    					if(peek(bucket)=='m'){
    					l2m=1;
    					pop(&bucket);
    					} else{
    					 l2m=0;
    					
    					insertLeft(l2,pop(&bucket)-'0');
    					//displayLR(l2);
    					}
    				}
    				else if(space==2){
					
    					if(peek(bucket)=='m'){
    					  //printf("peek bucket ' %c ' \n", peek(bucket));
    					  printf("%c \n",pop(&bucket));
    					 // printf("'%c'\n",peek(bucket));
    					 // break;
    					l1m=1;
    					//printf("pop bucket '%c' ",pop(&bucket));
    					//printf("peek buckut ' %c ' ",peek(bucket));
    					} else {l1m=0;
    					insertLeft(l1,pop(&bucket)-'0');
    					//displayLR(l1);
    					}
    				//displayLR(l1);
    				}
    			}
    		}
    			if(postfix->data=='+' && l2m==1 && l1m==1){
    			calculate(l1,l2,postfix->data,result);
    			push(&bucket,'m');
    			}
    			else if(postfix->data=='+' && (((l2m==1 && l1m!=1) && isgreater(l1,l2)==1) || (l2m==0 && l1m==1 &&  isgreater(l1,l2)==-1))){
    			calculate(l1,l2,'-',result);
    			push(&bucket,'m');
    			}
    			else if(postfix->data=='+' && (((l2m==1 && l1m!=1) && isgreater(l1,l2)==-1) || (l2m==0 && l1m==1 && isgreater(l1,l2)==1))){
    			calculate(l1,l2,'-',result);
    			}
    			else if(postfix->data=='+' && (l2m==1 || l1m==1 ) && isgreater(l1,l2)==0){
    			insertLeft(result,0);
    			}
    			else if(postfix->data=='+' && l2m==0 && l1m==0){
    			calculate(l1,l2,postfix->data,result);
    			//push(&bucket,'m');
    			}
    			else if(postfix->data=='-' && l2m==1 && l1m==1 && isgreater(l1,l2)==1){
    			calculate(l1,l2,'-',result);	
    			push(&bucket,'m');
    			}
    			else if(postfix->data=='-' && l2m==1 && l1m==1 && isgreater(l1,l2)==-1){
    			calculate(l1,l2,'-',result);	
    			}
    			else if(postfix->data=='-' && l2m==l1m && isgreater(l1,l2)==0){
    			    			insertLeft(result,0);
    			}
    			else if(postfix->data=='-' && l2m==0 && l1m==0 && isgreater(l1,l2)==1){
    			calculate(l1,l2,'-',result);	
    			}
    			else if(postfix->data=='-' && l1m==0 && l2m==0 && isgreater(l1,l2)==-1){
    			calculate(l1,l2,'-',result);	
    			push(&bucket,'m');
    			
    			}
    			else if(postfix->data=='-' && l2m==1 && l1m==0 ){
    			calculate(l1,l2,'+',result);
    			push(&bucket,'m');	
    			}
    			else if(postfix->data=='-' && l2m==0 && l1m==1 ){
    			calculate(l1,l2,'+',result);	
    			}
    			else if(postfix->data=='*' && l1m==l2m){
    			calculate(l1,l2,'*',result);	
    			}
    			else if(postfix->data=='*' && (l1m==1 || l2m==1)){
    			calculate(l1,l2,'*',result);	
    			push(&bucket,'m');	
    			}
   
    			else if(postfix->data=='/' && l1m==l2m){
    			calculate(l1,l2,'/',result);	
    			}
    			else if(postfix->data=='/' && (l1m==1 || l2m==1)){
    			calculate(l1,l2,'/',result);	
    			push(&bucket,'m');	
    			}
    			
    			//printf("coming here for result??\n");
    			displayLR(result);
    			//then we push the result back in 
    			node* p=result->front;
    			while(p){
    				push(&bucket,(char)((int)'0'+p->val));
    				p=p->next;
    			}
    			//printf("new here\n");
    			free(l1);
    			free(l2);
    			free(result);
    			printf("new here\n");
    			display(bucket);
    	}
    	else{
    		push(&bucket,postfix->data);
    		//printf("peek bucket %c \n",peek(bucket));
    	}
    	
    	//printf("postfix data: %c, ",postfix->data);
    	postfix=postfix->next;
    }
    
	display(bucket);
	/*delete(&l1);
    delete(&l2);
    delete(&result);
    //deleteStack(&s);
  //  delete(infix);
  //  delete(postfix);
//*/

	return 0;
}

