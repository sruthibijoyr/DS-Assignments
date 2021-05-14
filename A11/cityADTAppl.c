//Exercise 11

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"cityADTIf.h"

void main(){
     cityADT *c;
     int ch=0,flag;
     char source[25],destination[25];
     c = malloc(sizeof(cityADT));
     while(ch!=5){
          printf("\n**********MENU***********\n1)Create graph\n2)Display\n3)Check connectiviy\n4)DFS\n5)Exit\nEnter choice:");
          scanf("%d",&ch);
          switch(ch){
               case 1:
               create(c);
               break;

               case 2:
               disp(c);
               break;

               case 3:
               path(c);
               break;

               case 4:
               DFS(c);
               break;


          }
     }
}

/*

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
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

Enter number of direct connections:7

Enter source and destination:b a c d d e d b f e f a f c

Enter source and destination:
Enter source and destination:
Enter source and destination:
Enter source and destination:
Enter source and destination:
Enter source and destination:
**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
5)Exit
Enter choice:3

Enter source :c

Enter destination :a

Path exists from c to a :
c -> d -> b -> a

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
5)Exit
Enter choice:4

Enter source :d


Starting from d : a, b, e, can be visited.

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
5)Exit
Enter choice:4

Enter source :f


Starting from f : a, b, c, d, e, can be visited.

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
5)Exit
Enter choice:3

Enter source :f

Enter destination :e

Path exists from f to e :
f -> c -> d -> e

**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
5)Exit
Enter choice:3

Enter source :b

Enter destination :f

Path doesnt exist from b to f !


**********MENU***********
1)Create graph
2)Display
3)Check connectiviy
4)DFS
5)Exit
Enter choice:5
*/
