
typedef struct
{
	char stack[100];
	int top;
	int size;
}Stk;

int isFull(Stk S)
{
	if((S.top+1)>=S.size)
	{
		return 1;
	}
	else
		return 0;
}

int isEmpty(Stk S)
{
	if(S.top<0)
	{
		return 1;
	}
	else
		return 0;
}

void push(Stk *S,char x){
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

char pop(Stk *S){
     char ch;
	if(isEmpty(*S))
	{
		printf("\nStack is empty");
	}
	else
	{
	     ch = S->stack[S->top];
		S->top--;
	}
	return ch;
}

void display(Stk S)
{
	int i;
	if(isEmpty(S))
	{
		printf("\nStack is empty");
	}
	else
	{
		for(i=S.top;i>=0;--i)
		{
			printf("%c",S.stack[i]);
		}
	}
}

void initialize(Stk *S)
{
	S->size = 20;
	S->top=-1;
}



