
typedef struct mynode{
     char data;
     struct mynode *right,*left;
}node;


typedef struct
{
	long *stack[100];
	int top;
	int size;
}Stack;

int isFull(Stack S)
{
	if((S.top+1)>=S.size)
	{
		return 1;
	}
	else
		return 0;
}

int isEmpty(Stack S)
{
	if(S.top<0)
	{
		return 1;
	}
	else
		return 0;
}

void push(Stack *S,long *x){
	if(isFull(*S))
	{
		printf("\nStack is full!");
	}
	else
	{
		S->top++;
		S->stack[S->top]=x;
	}
}

long* pop(Stack *S){

    long *x;
	if(isEmpty(*S))
	{
		printf("\nStack is empty");
	}
	else
	{
	     x = S->stack[S->top];
		S->top--;
	}
	return x;
}


void initialize(Stack *S)
{
	S->size = 20;
	S->top=-1;
}



void pushch(Stack *S,char *x){
	if(isFull(*S))
	{
		printf("\nStack is full!");
	}
	else
	{
		S->top++;
		S->stack[S->top]=x;
	}
}

char popch(Stack *S){
     char ch;
	if(isEmpty(*S))
	{
		printf("\nStack is empty");
	}
	else
	{
	     ch = *S->stack[S->top];
		S->top--;
	}
	return ch;
}

