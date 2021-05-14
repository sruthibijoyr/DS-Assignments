
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"ExpTreeADT.h"

void main(){
     ExpTree exp;
     printf("\nEnter infix expression:");
     scanf("%s",exp.infix);
     infixToPostfix(&exp);
     printf("\nPostfix expression: %s",exp.postfix);
     exp.t = constExpTree(&exp);
    
    printf("\nContents of tree:");
    displayTree(exp.t);

     exp.value  = evaluate(exp.t);
     printf("\nValue :%d",exp.value);

}


