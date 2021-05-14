#include<stdio.h>
#include<stdlib.h>
#include"binaryHeapADTIf.h"
void main(){
     priorityQueueADT *p;
     p = init(p);
     data x,*temp;
     int ch=0;
     
     while(ch != 4){
          printf("\n*************MENU**************\n");
          printf("1)Insert element\n2)Display\n3)Delete\n4)Exit\nEnter choice:");
          scanf("%d",&ch);
          switch(ch){
               
               case 1:
               printf("\nEnter empid:");
               scanf("%d",&x.empid);
               printf("\nEnter name:");
               scanf("%s",x.name);
               printf("\nEnter salary:");
               scanf("%f",&x.salary);
               insert(p,x);
               break;
               
               case 2:
               display(p,1,0);
               break;
               
               case 3:
               temp = delete(p);
               if(temp == NULL){
               		printf("Queue empty!\n");
               }
               break;
               
               case 4:
               break;
               
          }
     }
}

/*
output:

Enter capacity:
30

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:1

Enter name:a

Enter salary:78000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:2

Enter name:b

Enter salary:34000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:3

Enter name:c

Enter salary:45000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:4

Enter name:d

Enter salary:24000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:5

Enter name:e

Enter salary:100000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:6

Enter name:f

Enter salary:15000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:1

Enter empid:7

Enter name:g

Enter salary:10000

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 7, NAME: g, SALARY: Rs.10000.00]
        [ID: 2, NAME: b, SALARY: Rs.34000.00]
                [ID: 1, NAME: a, SALARY: Rs.78000.00]
                [ID: 5, NAME: e, SALARY: Rs.100000.00]
        [ID: 6, NAME: f, SALARY: Rs.15000.00]
                [ID: 3, NAME: c, SALARY: Rs.45000.00]
                [ID: 4, NAME: d, SALARY: Rs.24000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 7, NAME: g, SALARY: Rs.10000.00]
        [ID: 2, NAME: b, SALARY: Rs.34000.00]
                [ID: 1, NAME: a, SALARY: Rs.78000.00]
                [ID: 5, NAME: e, SALARY: Rs.100000.00]
        [ID: 6, NAME: f, SALARY: Rs.15000.00]
                [ID: 3, NAME: c, SALARY: Rs.45000.00]
                [ID: 4, NAME: d, SALARY: Rs.24000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 6, NAME: f, SALARY: Rs.15000.00]
        [ID: 2, NAME: b, SALARY: Rs.34000.00]
                [ID: 1, NAME: a, SALARY: Rs.78000.00]
                [ID: 5, NAME: e, SALARY: Rs.100000.00]
        [ID: 4, NAME: d, SALARY: Rs.24000.00]
                [ID: 3, NAME: c, SALARY: Rs.45000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 4, NAME: d, SALARY: Rs.24000.00]
        [ID: 2, NAME: b, SALARY: Rs.34000.00]
                [ID: 1, NAME: a, SALARY: Rs.78000.00]
                [ID: 5, NAME: e, SALARY: Rs.100000.00]
        [ID: 3, NAME: c, SALARY: Rs.45000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 2, NAME: b, SALARY: Rs.34000.00]
        [ID: 1, NAME: a, SALARY: Rs.78000.00]
                [ID: 5, NAME: e, SALARY: Rs.100000.00]
        [ID: 3, NAME: c, SALARY: Rs.45000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 3, NAME: c, SALARY: Rs.45000.00]
        [ID: 1, NAME: a, SALARY: Rs.78000.00]
        [ID: 5, NAME: e, SALARY: Rs.100000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 1, NAME: a, SALARY: Rs.78000.00]
        [ID: 5, NAME: e, SALARY: Rs.100000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
[ID: 5, NAME: e, SALARY: Rs.100000.00]

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:2
Queue is empty!
*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:3
Queue empty!

*************MENU**************
1)Insert element
2)Display
3)Delete
4)Exit
Enter choice:4

*/