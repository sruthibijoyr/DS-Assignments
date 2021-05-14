#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int size;
	int *arr;
}numberADT;
void init(numberADT *N);
void insertElements (numberADT *N, int x[10]);
void lsearchElement(numberADT *N, int key);
void bsearchElement(numberADT *N, int key);
void display(numberADT *N);