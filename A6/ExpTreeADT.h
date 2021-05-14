#include"stack.h"



typedef struct{
     char infix[25];
     char postfix[25];
     int value;
     node *t;
}ExpTree;


node *initNode(node *x, char ch){
     x = (node *)malloc(sizeof(node));
     x->right = NULL;
     x->left = NULL;
     x->data = ch;
     return x;
}

void infixToPostfix(ExpTree *exp){
     int len = strlen(exp->infix);
     int j=0;
     char ch,popCh;
     Stack S;
     initialize(&S);
     for(int i=0;i<len;++i){
          ch = exp->infix[i];
          
          if(isdigit(ch)){
               exp->postfix[j] = ch;
               j++;
          }
          else if(S.top == -1 || ch == '^'){
               pushch(&S,&ch);
          }
          else if(ch == '*' || ch == '/'){
               while(S.top != -1 && *S.stack[S.top] != '-' && *S.stack[S.top] != '+'){
                    popCh = popch(&S);
                    exp->postfix[j] = popCh;
                    j++;
               }
               pushch(&S,&ch);
          }
          else if(ch == '+' || ch =='-'){
               while(S.top != -1 ){
                    popCh = popch(&S);
                    exp->postfix[j] = popCh;
                    j++;
               }
               pushch(&S,&ch);
          }
     } 
     
     if(isEmpty(S) != 1){
          while(isEmpty(S) != 1){
               popCh = popch(&S);
               exp->postfix[j] = popCh;
               j++;
          }
     }    
     exp->postfix[j] = '\0';
}

node* constExpTree(ExpTree *exp){
     char ch;
     Stack s;
     initialize(&s);
     int len = strlen(exp->postfix);
     node *x;
     x = NULL;
     for(int i=0;i<len;++i){
         ch = exp->postfix[i];
         
         if(isdigit(ch)){
            x = initNode(x,ch);
            push(&s,x);
         }
         else{
            x = initNode(x,ch);
            x->right = pop(&s);
            x->left = pop(&s);
            push(&s,x);
         }
     }
   //  displayN(exp.s);

   return x;

}

int evaluate(node *x){

  char operator;
  int operand1, operand2;
  if(x->left == NULL && x->right == NULL){
    return (x->data - '0');
  }
  else{
    operator = x->data;
    operand1 = evaluate(x->left);
    operand2 = evaluate(x->right);
    switch(operator){
      case '+':
              return operand1+operand2;
              break;
      case '-':
              return operand1-operand2;
              break;
      case '*':
              return operand1*operand2;
              break;
      case '/':
              return operand1/operand2;
              break;
    }
  }
}


void displayTree(node *x)
{
	if(x==NULL)
	{
		return;
	}
	displayTree(x->left);
	printf("%c ",x->data);
	displayTree(x->right);
}




