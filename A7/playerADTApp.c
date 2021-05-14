//binary search tree - player details


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"playerADTimpl.h"

void main(){
     
     int ch=0;
     char name[25];
     playerProfile *p,*temp;
     p = init(p);
     p = NULL;
     playerInfo d;
     while(ch != 8){
          printf("\n\n**********PLAYER INFORMATION*************\n");
          printf("\nMENU:\n1)Insert player records\n2)Display hierarchy of all players\n3)Delete\n4)Search\n5)Display player names - preorder\n6)Display player names - inorder\n7)Display player names - postorder\n8)Exit\nEnter choice:");
          scanf("%d",&ch);
          
          switch(ch){
          
               case 1:
                    printf("\nEnter player name:");
                    scanf("%s",d.name);
                    printf("\nEnter player role:");
                    scanf("%s",d.role);
                    printf("\nEnter average run rate:");
                    scanf("%f",&d.avgRunRate);
                    p = insert(p,d);
                    break;
                    
               case 2:
                    printf("\nPlayer Hierarchy:\n");
                    displayHierarchy(p,0);
                    break;
                    
               case 3:
                    printf("\nEnter player name to delete:");
                    scanf("%s",name);
                    p = delete(p,name);
                    break;
                  
               case 4:
                    printf("\nEnter player name to search:");
                    scanf("%s",name);
                    temp = init(temp);
                    temp = search(p,name);

                    if(temp != NULL)
                         printf("\nName: %s\nRole: %s\nAvg run rate: %.2f\n",temp->d.name,temp->d.role,temp->d.avgRunRate);
                    else
                         printf("Name not found in player records!\n");
                    break;

               case 5:
                    printf("Player names - preorder:\n");
                    preorder(p);
                    break;

               case 6:
                    printf("Player names - inorder:\n");
                    inorder(p);
                    break;

               case 7:
                    printf("Player names - postorder:\n");
                    postorder(p);
                    break;

               case 8:
                    break;
          
          } 
     }
}