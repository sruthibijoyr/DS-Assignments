#include "sortimpl.h"
void main()
{
	int ch=1;
	int i;
	numberADT *N;

	int key;
	int x[10];
	while(ch!=5)
	{
		printf("\n\n******MENU******\n1 - Insert Elements\n2 - Selection Sort\n3 - Shell sort\n4 - Display\n5 - Exit\nYour Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				N=malloc(sizeof(numberADT));
				init(N);
				for(i=0;i<10;i++)
				{
					printf("\nEnter the element: ");
					scanf("%d",&x[i]);
				}
				 insertElements(N,x);
				break;
			case 2:
				selSort(N);
				printf("Selection sort done\n");
				break;
			case 3:
				shellSort(N);
				printf("Shell sort done\n");
				break;
			case 4:
				display(N);
				break;
		}
	}
}

/*
OUTPUT



******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 1

Enter the element: 23

Enter the element: 34

Enter the element: 54

Enter the element: 65

Enter the element: 78

Enter the element: 87

Enter the element: 99

Enter the element: 103

Enter the element: 203

Enter the element: 506


******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 2

Enter the number to search for: 88
Element not present!


******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 2

Enter the number to search for: 87
Element found at index 5


******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 3

Enter the number to search for: 203
Element found at index 8


******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 3

Enter the number to search for: 77
Element not present!


******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 4
Contents of array:
23  34  54  65  78  87  99  103  203  506

******MENU******
1 - Insert Elements
2 - Linear Search
3 - Binary Search
4 - Display
5 - Exit
Your Choice: 5
*/
