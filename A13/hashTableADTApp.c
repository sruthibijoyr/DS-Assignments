#include<stdio.h>
#include<stdlib.h>
#include"hashTableADTIf.h"

int main()
{
	hashTableADT *h;
	node *p;
	h=malloc(sizeof(hashTableADT));
	int size,choice=0,key;
	printf("\nEnter size of hash table :");
	scanf("%d",&size);
	init(h,size);
	while(choice!=4)
	{
		printf("\n\n*************MENU************\n\n1) Insert a key into the hash table using the hash function\n2) Search an element in the hash table\n3) Display hash table\n4)Exit");
		printf("\nEnter choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter key to insert :");
				scanf("%d",&key);
				insertElement(h,key);
				break;

			case 2:
				printf("\nEnter element to search for :");
				scanf("%d",&key);
				p=searchElement(h,key);
				if(p!=NULL)
				{
					printf("%d found!\n",p->data);
				}
				else
				{
					printf("Not found!\n");
				}
				break;

			case 3:
				displayHT(h);
				break;

		}

	}
}


/*

output:


Enter size of hash table :10


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :6


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :2


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :45


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :5


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :8


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :98


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :11


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :31


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :28


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :33


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :3


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :13


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :12


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :90


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :40


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :68


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :3
0:      40      90
1:      31      11
2:      12      2
3:      13      3       33
4:
5:      5       45
6:      6
7:
8:      68      28      98      8
9:


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :2

Enter element to search for :40
40 found!


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :1

Enter key to insert :51


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :2

Enter element to search for :15
Not found!


*************MENU************

1) Insert a key into the hash table using the hash function
2) Search an element in the hash table
3) Display hash table
4)Exit
Enter choice :4


*/