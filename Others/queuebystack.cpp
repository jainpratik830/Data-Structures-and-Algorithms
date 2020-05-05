#include<iostream>
using namespace std;
#define MAX 5

string a[1000],b[1000];
int top1=-1,top2=-1;


void push(string x,int c)
{
        if(c==1){
        //if (top1>=1000)
        //cout << "Stack overflow" << endl;
        a[++top1]=x;
        cout << "hello";
        }
        if(c==2){
       // if (top2>=1000)
       // cout << "Stack overflow" << endl;
        b[++top2]=x;
        }

}

string pop(int c)
{
string y;
       if(c==1)
       {
       // if (top1<0)
       // cout << "Stack underflow" << endl;
        y=a[top1];
        top1=top1-1;
       }
       if(c==2)
       {
       // if (top2<0)
       // cout << "Stack underflow" << endl;
        y=b[top2];
        top2=top2-1;
       }
                return y;
}


void enqueue(string x)
{
    while(top1>=0)
        push(pop(1),2);
    cout<< "a";
    push(x,1);
    cout << "b";
    while(top2>=0)
        push(pop(2),1);
        cout << "c";
}

void dequeue()
{
   cout <<"Removing "<< pop(1)<<endl;
}


int main()
{
    int q;
    string b;
    while(q!=4)
    {
    cout<< "Choose any one of the following options: 1.EnQUEUE 2.dEQUEUE 3.Display 4.Exit" <<endl;
    cin >>q;
    switch (q)
    {
    case 1:
        {
            cout << "Ender the element" << endl;
            cin>> b;
            enqueue(b);
            break;
        }
    case 2:
        {
            dequeue();
            break;
        }
    case 3:
        {
            int i;
            //int n=sizeof(a);
            for(i=0;i<=top1;i++)
            {
            cout << a[i]<< endl;
            }
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
