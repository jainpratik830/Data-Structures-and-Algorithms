#include<string.h>
#include<iostream>
using namespace std;


char stack[25];
int top=-1;
/*
{
    if(a=='(')
        return 1;
    else if(a==')')
        return 1;
    else if(a=='^')
        return 5;
    else if(a=='*' ||a=='/')
        return 4;
    else if (a=='+' ||a=='-')
        return 3;
    else if(a=='#')
        return 1;
    else
        return 0;
}
*/

int prescedence(char a)
{
   switch(a) {
      case '+':
      case '-':
         return 2;
         break;
      case '*':
      case '/':
         return 3;
         break;
      case '(':
      case ')':
      case '#':
         return 1;
         break;
   }
}

int isoperator(char a)
{
    switch (a)
        {
            case ')':
            case '(':
            case '*':
            case '^':
            case '/':
            case '+':
            case '-':
                return 1;
            break;
                default:
                return 0;
        }
}


void push(char x)
{
    if (top>=25)
    cout << "Stack overflow" << endl;
    else
    {
        stack[++top]=x;

    }
}

char pop()
{
    //if (top<=0)
    //cout << "Stack underflow" << endl;
    //else
    //{
        return(stack[top--]);
    //}
}

void convert(char infix[],char postfix[])
{
    int i,j,a=0;
    stack[++top]='#';
    for(i=0;i<strlen(infix);i++)
    {
        a=infix[i];
        if (isoperator(a)==0)
        {
            postfix[j]==a;
            j++;
        }
        else
        {
            if (prescedence(a)=='(')
                push(a);
            else
            {
                if (prescedence(a)==')')
                {
                    while(stack[top] != '('){
                    postfix[j]=pop();
                    j++;
                    }

                pop();
            } else {
               if(prescedence(a)>prescedence(stack[top])) {
                  push(a);
               } else {

                  while(prescedence(a)<=prescedence(stack[top])) {
                     postfix[j] = pop();
                     j++;
                  }

                  push(a);
               }
            }
         }
      }
   }


while (stack[top]!='#')
{
    postfix[j]=pop();
    j++;
}

postfix[j]='\0';

}






int main()
{
   char infix[25]="1*(2+3)",postfix[25];
    cout<< "Infix expression is: " << infix  <<endl;
    convert(infix,postfix);
    cout<< "Postfix expression is: " << postfix << endl;
   return 0;
}

