#include<iostream>
using namespace std;

int main()
{
    int n;
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
        cout << a[i] << endl;

    for (int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
     cout << "The sorted array is " << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
}
