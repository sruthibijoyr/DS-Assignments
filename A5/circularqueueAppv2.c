#include<stdio.h>
#include<stdlib.h>

#include"circularqueuev2.h"

void main(){
	Queue q1,q2;
	Job job[20];
	char ch = 'y';
	int njob = 0, CBT1, CBT2;
	while(ch == 'y'){
		printf("\nEnter job name:");
		scanf(" %c",&job[njob].name);
		printf("\nEnter job CBT:");
		scanf("%d",&job[njob].CBT);
		njob++;
		printf("\nEnter more jobs?");
		scanf(" %c",&ch);
	}
	init(&q1);
	init(&q2);
	for(int i=0;i<njob;++i){
		CBT1 = calcCBT(q1);
		CBT2 = calcCBT(q2);
		if(CBT1 <= CBT2)
			enqueue(&q1,job[i]);
		else
			enqueue(&q2,job[i]);
	}
	printf("\n\n**********Allocated jobs:************\n");
	printf("\nQueue 1:");
	display(q1);	
	printf("\nQueue 2:");
	display(q2);
	
}

/*
Enter job name:A

Enter job CBT:2

Enter more jobs?y

Enter job name:B

Enter job CBT:4

Enter more jobs?y

Enter job name:C

Enter job CBT:8

Enter more jobs?y

Enter job name:D

Enter job CBT:5

Enter more jobs?y

Enter job name:E

Enter job CBT:2

Enter more jobs?y

Enter job name:F

Enter job CBT:7

Enter more jobs?y

Enter job name:G

Enter job CBT:4

Enter more jobs?y

Enter job name:H

Enter job CBT:3

Enter more jobs?y

Enter job name:I

Enter job CBT:6

Enter more jobs?y

Enter job name:J

Enter job CBT:6

Enter more jobs?n

Enter capacity of the queue:10

Enter capacity of the queue:10

**********Allocated jobs:************

Queue 1:A 2     C 8     F 7     I 6
Queue 2:B 4     D 5     E 2     G 4     H 3     J 6

*/