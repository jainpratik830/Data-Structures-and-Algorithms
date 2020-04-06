#include<iostream>
using namespace std;

int main()
{
    int n,temp;
    cout << "Please enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << endl <<"Please enter the elements: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "The original array is " << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << "   ";

    for (int i=0;i<n;i++)
    {
       for(int j=0;j<n-1-i;j++)
       {
            if(a[j+1]<a[j])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
       }
    }
     cout <<endl << "The sorted array is " << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << "   ";
}
