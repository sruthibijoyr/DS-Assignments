//circular queue


typedef struct{
	int *arr, front, rear, capacity,size;
}Queue;


int isEmpty(Queue q){
	if(q.size==0)
		return 1;
	else
		return 0;	
}

int isFull(Queue q){
	if(q.size == q.capacity)
		return 1;
	else
		return 0;	
}


void init(Queue *q){
	printf("\nEnter capacity of the queue:");
	scanf("%d",&q->capacity);
	q->front = q->rear = -1;
	q->size = 0;
	q->arr = (int *)malloc(sizeof(int)*q->capacity);
}

void enqueue(Queue *q, int x){
	if(isFull(*q)){
		printf("\nQueue is full!");
	}
	else{
		q->rear = (q->rear+1)%q->capacity;
		*(q->arr+q->rear) = x;
		q->size++;
	}
}

void dequeue(Queue *q){
	if(isEmpty(*q)){
		printf("\nQueue is empty!");
	}
	else{
		q->front = (q->front+1)%q->capacity;
		q->size--;
	}

}


void display(Queue q){
	int i;
	if(isEmpty(q)){
		printf("\nQueue is empty!");
	}
	else{
		printf("\nQueue:");
		for(i=q.front+1;i!=q.rear;i = (i+1)%q.capacity){
			printf("%d ",q.arr[i]);
		}
		printf("%d ",q.arr[i]);
	}
}
