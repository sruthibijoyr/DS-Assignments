#include"hashTableADTImpl.h"

void init(hashTableADT *h,int size);

int hash(int size,int x);

void insertElement(hashTableADT *h,int x);

node* searchElement(hashTableADT *h,int x);

void displayHT(hashTableADT *h);
