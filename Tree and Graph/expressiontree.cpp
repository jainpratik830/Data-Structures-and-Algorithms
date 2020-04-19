#include <iostream>
#include <cstring>

using namespace std;


struct node
{
    char a;
    node *leftchild,*rightchild;
};
node* s[100];
int t=-1;

void push(node* b)
{
        s[++t]=b;
}

void pop()
{
    t--;
}


node *newNode(char v)
{
    node *temp=new node;
    temp->a=v;
    temp->leftchild=NULL;
    temp->rightchild=NULL;
}

bool isOperator(char a)
{
    if(a=='+' ||a=='-' ||a=='*' ||a=='/' ||a=='^' )
        return true;
    else
        return false;
}

node* constructtree(char postfix[])
{
    node *a,*a1,*a2;
    for (int i=0;i<strlen(postfix);i++)
    {
        if(!isOperator(postfix[i]))
        {
            a = newNode(postfix[i]);
            push(a);
        }
        else
        {
            a1=s[t];
            pop();
            a2=s[t];
            pop();
            a = newNode(postfix[i]);
            a->leftchild=a2;
            a->rightchild=a1;
            push(a);
        }
    }
    a=s[t];
    pop();
    return a;
}

void inorder(node *a)
{
    if(a)
    {
        inorder(a->leftchild);
        cout<< a->a;
        inorder(a->rightchild);
    }
}


int main()
{
    char postfix[] = "ab+ef*g*-";
    node* r = constructtree(postfix);
    cout<< "infix expression is \n";
    inorder(r);
    return 0;
}
