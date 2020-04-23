#include<iostream>
using namespace std;
#define MAX 5

string a[1000];
int top=0;


void push(string x)
{
    if (top>=1000)
    cout << "Stack overflow" << endl;
    else
    {
        a[top]=x;
        top++;
    }
}

void pop()
{
    if (top<=0)
    cout << "Stack underflow" << endl;
    else
    {
        top=top-1;
    }
}




int main()
{
    int q;
    string b;
    while(q!=4)
    {
    cout<< "Choose any one of the following options: 1.Push 2.Pop 3.Display 4.Exit" <<endl;
    cin >>q;
    switch (q)
    {
    case 1:
        {
            cout << "Ender the element" << endl;
            cin>> b;
            push(b);
            break;
        }
    case 2:
        {
            pop();
            break;
        }
    case 3:
        {
            int i;
            //int n=sizeof(a);
            for(i=top-1;i>=0;i--)
            cout << a[i]<< endl;
            break;
        }
    case 4:
        break;
    default:
        {
            cout<<"Please enter a valid choice" << endl;
            break;
        }
    }
    }
}
