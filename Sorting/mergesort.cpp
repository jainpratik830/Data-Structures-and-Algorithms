#include<iostream>
using namespace std;


void merge(int *a,int l,int m,int h)
{
    int n1,n2;
    n1=m-l+1;
    n2=h-m;
    int L[n1],R[n2];
    int i,j,k;

    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int i=0;i<n2;i++)
        R[i]=a[m+1+i];

    k=l;
    i=0;
    j=0;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int *a,int l,int h)
{
    int m=(l+h)/2;
    if(l<h)
    {
        merge_sort(a,l,m);
        merge_sort(a,m+1,h);
        merge(a,l,m,h);
    }
}

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        cout << a[i] << "   ";
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    cout << endl << "Enter the elements: "<< endl;
    for(int i=0;i<n;i++)
        cin >> a[i];
    merge_sort(a,0,n-1);

    cout << "THe sorte array is: "<< endl;
    print(a,n);
}
