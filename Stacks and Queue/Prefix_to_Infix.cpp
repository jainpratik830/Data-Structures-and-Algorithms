#include<iostream>
using namespace std;

char a[100],b[100];

int l=0;

class stack
{
public:
    int t=0;
    string a[100];
   void push(string data)
   {
        if(t==100)
		cout << "Stack is Full"<< endl;
        else
	{
        a[t]=data;
        t++;
	}
    }

    string pop()
    {
        string k=a[t-1];
        if(t==0)
            {
            cout << "ERRROR:Stack is empty"<< endl;
            return 0;
            }
        else
        {
            t--;
            return k+"";
        }

    }
    string peek()
    {
        return a[t-1];
    }

    bool isempty()
    {
        return t;
    }

};
stack s1;

char reverse(char a[], int start, int end)
{

   int l=end+1;
   int m=l;
    int i=0;
    while(m>=0)
    {
        b[i]=a[m-1];
        m--;
        i++;
    }
    return l;


}

bool isOper(char a)
{
    if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^' )
        return 1;
    else
        return 0;
}

void pretoin(char c[])
{
    int q=0;
    while(q!=l)
    {
        if(!isOper(c[q]))
        {
           string abc(1,c[q]);
            s1.push(abc);
            q++;
        }
        else
        {

                cout <<"\nHello3";

                        string a=s1.a[s1.t-1];
                        s1.pop();
                        string b=s1.a[s1.t-1];
                        s1.pop();
                        string d="("+a+""+c[q]+""+b+")";
                        s1.push(d);
                q++;
            }
        }

     cout << "\ninfix is: ";
       cout<< s1.pop();
}

int main()
{
    char a[100];
    cout << "\nEnter the prefix expression: ";
    for(int q = 0;q<100;q++)
        a[q]='q';
    int x= 0;
    cin >> a;
    do{
        x++;
    }while(a[x]!='q');
    l=reverse(a,0,x-2);
    pretoin(b);

}
