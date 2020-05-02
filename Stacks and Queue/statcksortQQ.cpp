#include<iostream>
using namespace std;


class stack
{
public:
    int top=0;
    int a[];
    stack(int n)
    {
        int a[n];
    }
    void push(int x)
    {
        a[top]=x;
        top++;
    }
    int pop()
    {
        int k=a[top-1];
        top--;
        return k;
    }

};
void swap(int *a,int *b)
{

}


void sort(stack org,stack temp,int n)
{

    cout << n << "=nnn" <<endl;

    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        org.push(a);
    }
    int maxi,sized=n;
    n=5;
    cout <<"nn   " << n <<endl;
    while(n!=0)
    {
            cout << endl<< "Hello5";

        maxi=org.pop();
        cout <<n<<endl<< maxi << endl;
    n--;
    for(int i=0;i<n;i++)
    {
        int y=org.pop();
    cout << endl<< "Hello1  "<<y ;

        if(maxi<y)
        {
            cout << endl<< "Hello2";

        int temp1=maxi;
           maxi=y;
            temp.push(temp1);
        }
        else
        {
            temp.push(y);
        }
    }
    cout << maxi << endl;
    org.push(maxi);
    for(int i=0;i<n;i++)
    {
            cout << endl<< "Hello3";
            org.push(temp.pop());
    }
    }
    cout << "The sorted arry is: "<< endl;
    for(int i=0;i<sized;i++)
    {
        cout << endl<< "Hello4";
        int a=org.pop();
        cout << a << "      ";
    }
}

int main ()
{
    cout << "Size : ";
    int n;
    cin >> n;
        stack org(n),temp(n);
    cout << endl << "enter element: "<< endl;

    sort(org,temp,n);
}
