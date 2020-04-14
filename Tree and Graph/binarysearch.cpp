#include<iostream>
using namespace std;

int binarysearch(int arr[],int l,int h,int n)
{
    if (l <= h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==n)
            return mid;
        if(arr[mid]<n)
            return binarysearch(arr,mid+1,h,n);
        if(arr[mid]>n)
            return binarysearch(arr,l,mid-1,n);
        return -1;
    }
}

int main()
{
    int a[]={1,5,6,7,14,16,27,38,49,65};
    int n=sizeof(a)/sizeof(a[0]);
    int num=27;
    int index = binarysearch(a,0,n-1,num);
    if(index == -1)
      cout<< num <<" is not present in the array";
    else
      cout<< num <<" is present at index "<< index <<" in the array";
    return 0;
}



