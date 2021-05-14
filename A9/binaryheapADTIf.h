#include"binaryHeapADTImpl.h"

int isFull(priorityQueueADT *p);

void swap(data *det1, data *det2);

priorityQueueADT *init(priorityQueueADT *p);

void insert(priorityQueueADT *p,data x);

void display(priorityQueueADT *p,int index,int depth);

data* delete(priorityQueueADT *p);