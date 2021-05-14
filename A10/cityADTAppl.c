//Exercise 10: Check connectivity application for cities using BFS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"linearqueue.h"
#include"cityADTIf.h"

void main(){
     cityADT *c;
     int ch=0,flag;
     char source[25],destination[25];
     c = malloc(sizeof(cityADT));
     while(ch!=5){
          printf("\n**********MENU***********\n1)Create graph\n2)Display\n3)Check connectiviy\n4)BFS\n5)Exit\nEnter choice:");
          scanf("%d",&ch);
          switch(ch){
               case 1:
               create(c);
               break;

               case 2:
               disp(c);
               break;

               case 3:
               printf("\nEnter source:");
               scanf("%s",source);
               printf("\nEnter destination:");
               scanf("%s",destination);
               flag=connect(c,source,destination);
               if(flag==1){
               	printf("\nConnection exists from %s to %s",source,destination);
               }
               else{
               	printf("\nConnection doesn't exist from %s to %s",source,destination);
               }
               break;

               case 4:
               BFS(c);
               break;


          }
     }
}

/*

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)BFS
5)Exit
Enter choice:1

Enter city 1:a

Enter more cities? (y/n):y

Enter city 2:b

Enter more cities? (y/n):y

Enter city 3:c

Enter more cities? (y/n):y

Enter city 4:d

Enter more cities? (y/n):y

Enter city 5:e

Enter more cities? (y/n):y

Enter city 6:f

Enter more cities? (y/n):n

Enter number of direct connections:8

Enter source and destination:a b

Enter source and destination:b c

Enter source and destination:c a

Enter source and destination:a e

Enter source and destination:e f

Enter source and destination:f e

Enter source and destination:d a

Enter source and destination:d e

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)BFS
5)Exit
Enter choice:2


There exists a direct connection between a and b
There exists a direct connection between a and e
There exists a direct connection between b and c
There exists a direct connection between c and a
There exists a direct connection between d and a
There exists a direct connection between d and e
There exists a direct connection between e and f
There exists a direct connection between f and e
**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)BFS
5)Exit
Enter choice:3

Enter source:c

Enter destination:d

Connection doesn't exist from c to d
**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)BFS
5)Exit
Enter choice:3

Enter source:d

Enter destination:c

Connection exists from d to c
**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)BFS
5)Exit
Enter choice:4

Enter source :b


Starting from b :
c has been visited
a has been visited
e has been visited
f has been visited
**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)BFS
5)Exit
Enter choice:5
*/
