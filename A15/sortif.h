#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int size;
	int *arr;
}numberADT;
void init(numberADT *N);
void insertElements (numberADT *N, int x[10]);
void selSort(numberADT *N);
void shellSort(numberADT *N);
void display(numberADT *N);
