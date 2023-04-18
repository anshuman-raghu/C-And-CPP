#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


#define MAX 20
typedef char datatype;
typedef struct stack
{
    datatype a[MAX];
    int top;
}stack;  

void initialize(stack *p)
{
    p->top=-1;
}

int full(stack *p){
    if(p->top==MAX)
    return 1;
    else return 0;
    
}
int empty(stack *p){
    if(p->top==-1)
    return 1;
    else return 0;
    
}

void push(stack *p,datatype d)
{
    if(full(p))
    {
        printf("Stack overflow\n");
        exit(12345);
    }
    p->a[++(p->top)]=d;
}
datatype pop(stack *p)
{
    if(empty(p))
    {
        printf("Stack underflow\n");
        exit(54321);
    }
    return p->a[p->top--];
}
datatype peak(stack *p)
{
    if(empty(p))
    {
        printf("Stack is empty\n");
        exit(852369);
    }
    return p->a[p->top];
}

int compareOpra(char sym,char topOp);
void inToPost(char *inFix,char *postFix);
int main()
{
	char inFix[20], postFix[20];

	printf("Enter expression in infix: ");
	gets(inFix);

	inToPost(inFix, postFix);

	printf("The equivalent postfix expression is: %s \n", postFix);

	return 0;
}

int compareOpra(char sym,char topOp)
{
    char oprator[3][3]={{'+','-',0},{'*','/','%'},{'(',')',0}};
    int symRow,topOpRow;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(sym==oprator[i][j]) symRow=i;//0
            if(topOp==oprator[i][j]) topOpRow=i;//1
        }
    }
    if(symRow>topOpRow)return -1;
    if(symRow<topOpRow)return 1;
    if(symRow==topOpRow)return 0;
}

void inToPost(char *inFix,char *postFix)
{
    char sym,topOp;
    char temp[2]={'\0','\0'};
    stack s;

    initialize(&s);
    *postFix='\0';

    while(*inFix)
    {
        sym=*inFix;

        if(isalnum(sym))
        {
            temp[0]=sym;
            strcat(postFix,temp);
        }
        else if(empty(&s)||sym=='('||peak(&s)=='('){
            push(&s,sym);
        }
        
        else //it mean it is oprator and stack is not empty
        {
            if(sym==')')
            {
                while(!(peak(&s)=='('))
                {
                    temp[0]=pop(&s);
                    strcat(postFix,temp);
                }
                pop(&s);
            }
            else if(compareOpra(sym,peak(&s))==-1)
            {
                push(&s,sym);
            }
            else //sym have less or equal priorty as top oprator;
            {
                while(!empty(&s)&&compareOpra(sym,peak(&s))>=0)
                {
                    temp[0]=pop(&s);
                    strcat(postFix,temp);
                }
                push(&s,sym);
            }
        }
        
        ++inFix;
    }
    while (!empty(&s))
    {
        temp[0]=pop(&s);
        strcat(postFix,temp);
    }

}


/* if( always push,) pop till (*/


