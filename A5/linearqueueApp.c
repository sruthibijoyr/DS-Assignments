#include<stdio.h>
#include<stdlib.h>
#include"linearqueue.h"

void main(){

	Queue q;
	init(&q);
	int ch=0,x;
	while(ch !=4)
	{
		printf("\n\n*********MENU********\n");
		printf("1)Enqueue	2)Dequeue	3)Display	4)Exit\nEnter choice:");
		scanf("%d",&ch);
		switch(ch){
		
			case 1:
				printf("\nEnter data to enqueue:");
				scanf("%d",&x);
				enqueue(&q,x);
				break;
				
			case 2:
				dequeue(&q);
				break;
				
			case 3:
				display(q);
				break;
			case 4:
				break;
		}
	}
}


/*
output:

Enter capacity of the queue:5


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:1

Enter data to enqueue:1


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:1

Enter data to enqueue:2


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:1

Enter data to enqueue:3


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:1

Enter data to enqueue:4


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:1

Enter data to enqueue:5


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:1

Enter data to enqueue:6

Queue is full!

*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:3

Queue:1 2 3 4 5 

*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:2


*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:3

Queue:2 3 4 5 

*********MENU********
1)Enqueue	2)Dequeue	3)Display	4)Exit
Enter choice:4

*/
