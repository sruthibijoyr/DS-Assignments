#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include"stackIf.h"

char *infixToPostfix(char *infix, Stack *S);

int evaluateExp(char *postfix, Stack *S);


void main(){

     char *infix, *postfix;
     infix = (char *)malloc(sizeof(char)*20);
     int value;
     Stack S1,S2;
     initialize(&S1);
     initialize(&S2);
     printf("\n\n*************Infix to postfix**************");
     printf("\n\nEnter in-fix expression:");
     scanf("%s",infix);
     postfix = infixToPostfix(infix,&S1);
     printf("\n\nPost-fix expression : %s",postfix);
     printf("\n\n\n*************Evaluation of postfix**************");
     value = evaluateExp(postfix,&S2);
     printf("\n\nValue of expression : %d\n",value);
     
}


char *infixToPostfix(char *infix, Stack *S){
     int len = strlen(infix);
     int j=0;
     char ch,popch,*postfix;
     postfix = (char *)malloc(sizeof(char)*len);
     for(int i=0;i<len;++i){
          ch = *(infix+i);
          
          if(isdigit(ch)){
               *(postfix+j) = ch;
               j++;
          }

          else if(S->top == -1 || ch == '^' ){
               push(S,ch);
          }

          else if(ch == '*' || ch == '/'){
               while(S->top != -1 && *(S->stack+S->top) != '-' && *(S->stack+S->top) != '+'){
                    popch = pop(S);
                    *(postfix+j) = popch;
                    j++;
               }
               push(S,ch);
          }

          else if(ch == '+' || ch =='-'){
               while(S->top != -1 ){
                    popch = pop(S);
                    *(postfix+j) = popch;
                    j++;
               }
               push(S,ch);
          }
     } 
     
     if(isEmpty(*S) != 1){
          while(isEmpty(*S) != 1){
               popch = pop(S);
               *(postfix+j) = popch;
               j++;
          }
     }    
     *(postfix+j) = '\0';

     return postfix;
}



int evaluateExp(char *postfix, Stack *S){

     char ch, term, popch;
     int len = strlen(postfix),op1,op2;
     for(int i=0;i<len;++i){
          ch = *(postfix+i);
          
          if(isdigit(ch)){
               push(S,ch);
          }
          
          else{
               popch = pop(S);
               op2 = popch - '0';
               popch = pop(S);
               op1 = popch - '0';
               switch(ch){
                    case '+':
                             term = (char)(op1 + op2) + '0';
                      
                             break;
                            
                    case '-':
                             term = (char)(op1 - op2) + '0';
                       
                             break;
                             
                    case '*':
                              term = (char)(op1*op2) + '0';
                           
                              break;
                              
                    case '/':
                             term = (char)(op1 / op2) + '0';
                    
                             break;
                             
                    case '^':
                             term = (char)(pow(op1,op2)) + '0';
                          
                             break;
                            
               }
               
               push(S,term);
          }
     }
     popch = pop(S);
     return (popch - '0');
}









/*

output:

*************Infix to postfix**************

Enter in-fix expression:3+6/2*3^2


Post-fix expression : 362/32^*+


*************Evaluation of postfix**************

Value of expression : 30

*/