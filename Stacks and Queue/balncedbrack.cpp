#include<string.h>
#include<iostream>
using namespace std;
char stack[25];
int top=-1;

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
    //elsein
    int x=stack[top];
    top--;
    //{
        return x;
    //}
}

int main()
{
    char a[50];
    cin >> a;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='('||a[i]=='['||a[i]=='{'){

            push(a[i]);
        }
        else{
                if(a[i]==')'&&pop()=='(')
                {
                   continue;
                }
                else if(a[i]=='}'&&pop()=='{')
                    {
                   continue;
                }
                else if(a[i]==']'&&pop()=='[')
                {
                   continue;
                }

                else{
                    cout << "It is not balanced";
                    return 0;
                }

        }
    }
        cout << "\nIt is balanced";

}
