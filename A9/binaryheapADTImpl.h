typedef struct{
     int empid;
     char name[25];
     float salary;
}data;


typedef struct{
     int capacity;
     int size;
     data *empDetails;
}priorityQueueADT;

int isFull(priorityQueueADT *p){
     if(p->size == p->capacity){
          return 1;
     }
     else
          return 0;
}

void swap(data *det1, data *det2){
     data *temp;
     temp = det1;
     det1 = det2;
     det2 = temp;
}

priorityQueueADT *init(priorityQueueADT *p){
     p = malloc(sizeof(priorityQueueADT));
     printf("Enter capacity:\n");
     scanf("%d",&p->capacity);
     p->size = 0;
     p->empDetails = malloc(sizeof(data)*p->capacity); 
     p->empDetails[0].empid = -10;
     p->empDetails[0].salary = -10;
     return p;
}

void insert(priorityQueueADT *p,data x){
     int i;
     if(isFull(p)){
          printf("Queue is full!");
     }
     else{
          for(i=++p->size;p->empDetails[i/2].salary < x.salary && i!=1;i/=2){
               p->empDetails[i] = p->empDetails[i/2];
          }
          p->empDetails[i]=x;
     }
     while (i != 1 && p->empDetails[i/2].salary < p->empDetails[i].salary) 
    { 
       swap(&p->empDetails[i], &p->empDetails[i/2]); 
       i/=2;
    } 
}

void display(priorityQueueADT *p,int index,int depth){
     if(p->size == 0){
          printf("Queue is empty!");
     }
     else{
          for(int i=0;i<depth;++i){
               printf("\t");
          }
          if(index<=p->size){
               printf("[ID: %d, NAME: %s, SALARY: Rs.%.2f]\n",p->empDetails[index].empid,p->empDetails[index].name,p->empDetails[index].salary);
               if(index*2 <= p->size)
                    display(p,index*2,depth+1);
               if(index*2+1<=p->size)
                    display(p,index*2+1,depth+1);
          }
     }
}

data* delete(priorityQueueADT *p){

     if(p->size == 0){
          return NULL;
     }
     else{
          int i,child;
          data minEmp, lastEmp,*temp;
          minEmp = p->empDetails[1];
          temp=&p->empDetails[0];
          lastEmp = p->empDetails[p->size--];
          for(i=1;i*2<=p->size;i=child){
               child = i*2;
               if(p->empDetails[child+1].salary > p->empDetails[child].salary)
                    child++;
               if(lastEmp.salary < p->empDetails[child].salary){
                    p->empDetails[i] = p->empDetails[child];
               }
               else
                    break;
          }
          p->empDetails[i] = lastEmp;
          return temp;
     }
}


void enqueue(priorityQueueADT *pq, int x)
{
	pq->arr[++size]=x;
	for(int i=pq->size;i>1;i/=2)
	{
		if(pq->arr[i]>pq->arr[i/2])
		{
			swap();
		}
		else
		{
			break;
		}
	}
}