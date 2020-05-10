#include<iostream>
#include<climits>

using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

class heap
{
public:
    int *h_arr;
    int capacity;
    int h_size;
    heap(int cap)
    {
        h_size = 0;
        capacity = cap;
        h_arr = new int[cap];
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i);
    }
    int right(int i)
    {
        return (2*i+1);
    }
    int get_min()
    {
         return h_arr[0];
    }

    void insertkey(int k)
    {
        if (h_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        h_size++;
       // cout<< h_size << endl;
        int i=h_size-1;
        h_arr[i]=k;
        while(i!=0 && h_arr[parent(i)]>h_arr[i])
        {
            swap( &h_arr[parent(i)],&h_arr[i]);
            i=parent(i);
        }
    }

    void decrease_key(int i,int k)
    {
        h_arr[i]=k;
        while(i!=0 && h_arr[parent(i)]>h_arr[i])
        {
            swap( &h_arr[parent(i)],&h_arr[i]);
            i=parent(i);
        }
    }

    int extract_min()
    {

        cout << "hello1" << endl;
        if (h_size == 1)
        {
            h_size--;
            return h_arr[0];
        }
        int k=h_arr[0];
        h_arr[0]=h_arr[h_size-1];
        h_size--;
        MinHeapify(0);
        return k;
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
    if (l < h_size && h_arr[l] < h_arr[i])
        smallest = l;
    if (r < h_size && h_arr[r] < h_arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&h_arr[i], &h_arr[smallest]);
        MinHeapify(smallest);
    }
    }

    void deletekey(int i)
    {
        decrease_key(i, INT_MIN);
        extract_min();
    }

};


int main()
{
    heap h(11);
    h.insertkey(3);
    h.insertkey(2);
//    h.deletekey(1);
    h.insertkey(15);
    h.insertkey(5);
    h.insertkey(4);
    h.insertkey(45);
    //cout << h.extract_min() << " ";
  //  cout << h.get_min() << " ";
//    h.decrease_key(2,1);
  //  cout << h.get_min();

    int k=h.h_size;
    int a[k];
    for(int i=0;i<k;i++)
        a[i]= h.extract_min();
     return 0;
}
