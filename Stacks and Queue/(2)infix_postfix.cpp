#include<iostream>
#include<string.h>
using namespace std;


char stack[25];
int top = -1;

void push(char item) {
   stack[++top] = item;
}

char pop() {
   return stack[top--];
}

int precedence(char symbol) {

   switch(symbol) {
      case '+':
      case '-':
         return 2;
         break;
      case '*':
      case '/':
         return 3;
         break;
      case '^':
         return 4;
         break;
      case '(':
      case ')':
      case '#':
         return 1;
         break;
   }
}

int isOperator(char symbol) {

   switch(symbol) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '(':
      case ')':
         return 1;
      break;
         default:
         return 0;
   }
}


void convert(char infix[],char postfix[]) {
   int i,symbol,j = 0;
   stack[++top] = '#';

   for(i = 0;i<strlen(infix);i++) {
      symbol = infix[i];

      if(isOperator(symbol) == 0) {
         postfix[j] = symbol;
         j++;
      } else {
         if(symbol == '(') {
            push(symbol);
         } else {
            if(symbol == ')') {

               while(stack[top] != '(') {
                  postfix[j] = pop();
                  j++;
               }

               pop();
            } else {
               if(precedence(symbol)>precedence(stack[top])) {
                  push(symbol);
               } else {

                  while(precedence(symbol)<=precedence(stack[top])) {
                     postfix[j] = pop();
                     j++;
                  }

                  push(symbol);
               }
            }
         }
      }
   }

   while(stack[top] != '#') {
      postfix[j] = pop();
      j++;
   }

   postfix[j]='\0';
}

int stack_int[25];


int main() {
   char infix[50],postfix[50];
   cin >> infix;
   convert(infix,postfix);
   cout << postfix;
    return 0;
}
