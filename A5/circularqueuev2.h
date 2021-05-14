//circular queue

typedef struct{
	char name[5];
	int CBT;
}Job;

typedef struct{
	Job *job;
	int front, rear, capacity,size;
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
	q->job = (Job *)malloc(sizeof(Job)*q->capacity);
}

void enqueue(Queue *q, Job job){
	if(isFull(*q)){
		printf("\nQueue is full!");
	}
	else{
		q->rear = (q->rear+1)%q->capacity;
		*(q->job+q->rear) = job;
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

		for(i=q.front+1;i!=q.rear;i = (i+1)%q.capacity){
			printf("%c %d\t",q.job[i].name,q.job[i].CBT);
		}
		printf("%c %d ",q.job[i].name,q.job[i].CBT);
	}
}

int calcCBT(Queue q){
	int CBT=0,i;
	for(i=0;i<q.size;i++){
		CBT += q.job[i].CBT;
	}
	return CBT;
}
