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


    for (int i=0;i<n-1;i++)
    {
        int temp,mini;
        mini=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[mini]>a[j])
                mini=j;
        }
                temp=a[i];
                a[i]=a[mini];
                a[mini]=temp;
    }
    cout << "The sorted array is " << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
}
