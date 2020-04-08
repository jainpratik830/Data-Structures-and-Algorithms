#include<iostream>
using namespace std;

void swapp(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partiition(int *a,int start,int ende)
{
    int pivot=a[ende];
    int partindex=start;
    for (int i=start;i<=ende-1;i++)
    {
        if(a[i]<=pivot)
        {
            swapp(&a[i],&a[partindex]);
            partindex++;
        }
    }
    swapp(&a[partindex],&a[ende]);
    return partindex;
}

void quicksort(int *a,int start,int ende)
{
    if(start<ende)
    {
        int partindex=partiition(a,start,ende);
        quicksort(a,start,partindex-1);
        quicksort(a,partindex+1,ende);
    }
}

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

    quicksort(a,0,n-1);

    cout << "The sorted array is " << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
}

