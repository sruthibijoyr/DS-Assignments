//Exercise 11

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"cityADTIf.h"

void main(){
     cityADT *c;
     int ch=0,flag;
     char source[25],destination[25];
     c = malloc(sizeof(cityADT));
     while(ch!=5){
          printf("\n**********MENU***********\n1)Create graph\n2)Display\n3)Dijkstra's algorithm\n4)Find shortest path between 2 citites\n5)Exit\nEnter choice:");
          scanf("%d",&ch);
          switch(ch){
               case 1:
               create(c);
               break;

               case 2:
               disp(c);
               break;

               case 3:
               printf("Enter source : \n");
               scanf("%s",source);
               dijkstras(c,source);
               break;

               case 4:
               printf("Enter source : \n");
               scanf("%s",source);
               printf("Enter destination : \n");
               scanf("%s",destination);
               displayPath(c,source,destination);
               break;


          }
     }
}

/*


**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:1

Enter city 1:a y b y c n

Enter more cities? (y/n):
Enter city 2:
Enter more cities? (y/n):
Enter city 3:
Enter more cities? (y/n):
Enter number of direct connections:3

Enter source and destination:a b 3

Enter cost :
Enter source and destination:b c 4

Enter cost :
Enter source and destination:c a 1

Enter cost :
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:3
Enter source :
a

                *******INITITIAL STATE********
vertex  k       d       v
a       0       0       a
b       0       10000   a
c       0       10000   a
                *******WHEN a IS KNOWN********
vertex  k       d       v
a       1       0       a
b       0       3       a
c       0       10000   a
                *******WHEN b IS KNOWN********
vertex  k       d       v
a       1       0       a
b       1       3       a
c       0       7       b
                *******WHEN c IS KNOWN********
vertex  k       d       v
a       1       0       a
b       1       3       a
c       1       7       b
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:2

0 3 0
0 0 4
1 0 0

There exists a direct connection between a and b
There exists a direct connection between b and c
There exists a direct connection between c and a
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:3
Enter source :
b

                *******INITITIAL STATE********
vertex  k       d       v
a       0       10000   a
b       0       0       a
c       0       10000   a
                *******WHEN b IS KNOWN********
vertex  k       d       v
a       0       10000   a
b       1       0       a
c       0       4       b
                *******WHEN c IS KNOWN********
vertex  k       d       v
a       0       5       c
b       1       0       a
c       1       4       b
                *******WHEN a IS KNOWN********
vertex  k       d       v
a       1       5       c
b       1       0       a
c       1       4       b
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:3
Enter source :
c

                *******INITITIAL STATE********
vertex  k       d       v
a       0       10000   a
b       0       10000   a
c       0       0       a
                *******WHEN c IS KNOWN********
vertex  k       d       v
a       0       1       c
b       0       10000   a
c       1       0       a
                *******WHEN a IS KNOWN********
vertex  k       d       v
a       1       1       c
b       0       4       a
c       1       0       a
                *******WHEN b IS KNOWN********
vertex  k       d       v
a       1       1       c
b       1       4       a
c       1       0       a
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:4
Enter source :
a
Enter destination :
b

Path exists from a to b with total cost 3 .
a -> b
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:4
Enter source :
b
Enter destination :
a

Path exists from b to a with total cost 5 .
b -> c -> a
**********MENU***********
1)Create graph
2)Display
3)Dijkstra's algorithm
4)Find shortest path between 2 citites
5)Exit
Enter choice:5
*/
