
typedef struct
{
	char *stack;
	int top;
	int size;
  int capacity;
}Stack;

int isFull(Stack S)
{
	if(S.size >= S.capacity)
	{
		return 1;
	}
	else
		return 0;
}

int isEmpty(Stack S)
{
	if(S.size == 0)
	{
		return 1;
	}
	else
		return 0;
}

void push(Stack *S,char x){
	if(isFull(*S))
	{
		printf("\nStack is full!");
	}
	else
	{
		S->top++;
		S->stack[S->top]=x;
    S->size++;
	}
}

char pop(Stack *S){
     char ch;
	if(isEmpty(*S))
	{
		printf("\nStack is empty");
	}
	else
	{
    ch = S->stack[S->top];
		S->top--;
    S->size--;
	}
	return ch;
}

void display(Stack S)
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

void initialize(Stack *S)
{
	S->size = 0;
	S->top=-1;
  S->capacity = 20;
  S->stack = (char *)malloc(sizeof(char)*S->capacity);
}



