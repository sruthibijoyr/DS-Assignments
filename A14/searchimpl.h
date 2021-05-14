#include "searchif.h"

void init(numberADT *N)
{
	N->size=10;
	N->arr=malloc(sizeof(int)*10);
}
void insertElements (numberADT *N, int x[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		N->arr[i]=x[i];
	}
}
void lsearchElement(numberADT *N, int key)
{
	int i;
	int found=0;
	for(i=0;i<N->size;i++)
	{
		if(N->arr[i]==key)
		{
			printf("Element found at index %d\n",i);
			// printf("condition");
			found=1;
			break;
		}
	}
	if(found==0)
		printf("Element not present!\n");
}
void bsearchElement(numberADT *N, int key)
{
	int l,r,mid;
	l=0;
	r=N->size-1;
	mid=(l+r)/2;
	int found=0;
	while(found==0&&r>l)
	{
		if(key<N->arr[mid])
		{
			r=mid-1;
		}
		else if(key==N->arr[mid])
			found=1;
		else
			l=mid+1;
		mid=(l+r)/2;
	}
	if(found==1)
		printf("Element found at index %d\n",mid);
	else
		printf("Element not present!\n");
}
void display(numberADT *N)
{
	int i;
	printf("Contents of array: \n");
	for(i=0;i<N->size;i++)
	{
		printf("%d  ",N->arr[i]);
	}
}