
typedef struct mynode
{
	int data;
	struct mynode *link;
}node;

typedef struct 
{
	int size;
	node *arr[50];
}hashTableADT;

void init(hashTableADT *h,int size)
{
	h->size=size;
	for(int i=0;i<h->size;i++)
	{
		h->arr[i]=malloc(sizeof(node));
		h->arr[i]->link=NULL;
	}
}

int hash(int size,int x)
{
	return x%size;
}

void insertElement(hashTableADT *h,int x)
{
	int pos;
	pos=hash(h->size,x);
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=x;
	temp->link=h->arr[pos]->link;
	h->arr[pos]->link=temp;
}

node* searchElement(hashTableADT *h,int x)
{
	node *temp;
	int pos=hash(h->size,x);
	temp=h->arr[pos]->link;
	while(temp != NULL)
	{
		if(temp->data == x)
		{
			return temp;
		}
		temp = temp->link;
	}
	return NULL;
}

void displayHT(hashTableADT *h)
{
	node *temp;
	for(int i=0;i<h->size;++i)
	{
		printf("%d:\t",i);
		temp=h->arr[i]->link;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
