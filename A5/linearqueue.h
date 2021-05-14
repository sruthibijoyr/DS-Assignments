//linear queue

typedef struct{
	int *arr, front, rear, capacity;
}Queue;


int isEmpty(Queue q){
	if(q.front == q.rear)
		return 1;
	else
		return 0;	
}

int isFull(Queue q){
	if(q.rear == q.capacity-1)
		return 1;
	else
		return 0;	
}


void init(Queue *q){
	printf("\nEnter size of the queue:");
	scanf("%d",&q->capacity);
	q->front = q->rear = -1;
	q->arr = (int *)malloc(sizeof(int)*q->capacity);
}

void enqueue(Queue *q, int x){
	if(isFull(*q)){
		printf("\nQueue is full!");
	}
	else{
		q->rear++;
		*(q->arr+q->rear) = x;
	}
}

void dequeue(Queue *q){
	if(isEmpty(*q)){
		printf("\nQueue is empty!");
	}
	else{
		q->front++;
	}

}


void display(Queue q){
	if(isEmpty(q)){
		printf("\nQueue is empty!");
	}
	else{
		printf("\nQueue:");
		for(int i=q.front+1;i<=q.rear;++i){
			printf("%d ",q.arr[i]);
		}
	}
}
