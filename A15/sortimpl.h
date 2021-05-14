#include "sortif.h"

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
void selSort(numberADT *N)
{
	int temp,minimum;
        for(int i = 0; i < N->size-1 ; i++)
	{

		minimum = i ;
		for(int j = i+1; j < N->size ; j++ )
		{
			if(N->arr[ j ] < N->arr[ minimum ])
			{                
				minimum = j ;
			}
		}
		temp=N->arr[minimum];
		N->arr[minimum] = N->arr[i];
		N->arr[i]=temp; 
        }
}

void shellSort(numberADT *N) 
{
	int i, j, k, tmp;

	for (i = N->size / 2; i > 0; i = i / 2)

	{

	for (j = i; j < N->size; j++)

	{

	    for(k = j - i; k >= 0; k = k - i)

	    {

		if (N->arr[k+i] >= N->arr[k])

		    break;

		else

		{

		    tmp = N->arr[k];

		    N->arr[k] = N->arr[k+i];

		    N->arr[k+i] = tmp;

		}

	    }

	}

    }
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
