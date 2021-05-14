#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include"stackIf.h"

void main(){


     Stack S;
	initialize(&S);
	int choice=0;
	char cont,x;
	while(choice==0)
	{
		printf("\nMENU: 1) push	2)pop	3)display elements  4)Exit");
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element:");
				scanf(" %c",&x);
				push(&S,x);
				break;
			case 2:
				pop(&S);
				break;
			case 3:
				display(S);
				break;
			case 4:
				exit(0);
			default:
				choice=0;
				printf("\nInvaid option");
		}
		printf("\nEnter more?(y/n)");
		scanf(" %c",&cont);
		if(cont=='y')
		{
			choice=0;
		}
		else
		{
			choice=1;
		}
	}
     
}


/*

output:



MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:2

Stack is empty
Enter more?(y/n)y

MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:1
Enter element:a

Enter more?(y/n)y

MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:1
Enter element:b

Enter more?(y/n)y

MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:1
Enter element:c

Enter more?(y/n)y

MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:3
cba
Enter more?(y/n)y

MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:2

Enter more?(y/n)y

MENU: 1) push   2)pop   3)display elements  4)Exit
Enter choice:3
ba
Enter more?(y/n)n


*/