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
private:
    int *h_arr;
    int capacity;
    int h_size;
public:
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
    int get_max()
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
        int i=h_size-1;
        h_arr[i]=k;
        while(i!=0 && h_arr[parent(i)]< h_arr[i])
        {
            swap( &h_arr[parent(i)],&h_arr[i]);
            i=parent(i);
        }
    }

    void increase_key(int i,int k)
    {
        h_arr[i]=k;
        while(i!=0 && h_arr[parent(i)]< h_arr[i])
        {
            swap( &h_arr[parent(i)],&h_arr[i]);
            i=parent(i);
        }
    }

    int extract_max()
    {
        if (h_size == 1)
        {
            h_size--;
            return h_arr[0];
        }
        int k=h_arr[0];
        h_arr[0]=h_arr[h_size-1];
        h_size--;
        MaxHeapify(0);
        return k;
    }

    void MaxHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
    if (l < h_size && h_arr[l] > h_arr[i])
        smallest = l;
    if (r < h_size && h_arr[r] > h_arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&h_arr[i], &h_arr[smallest]);
        MaxHeapify(smallest);
    }
    }

    void deletekey(int i)
    {
        increase_key(i, INT_MAX);
        extract_max();
    }

};


int main()
{
    heap h(11);
    h.insertkey(3);
    h.insertkey(2);
    h.insertkey(1);
    h.insertkey(15);
    h.insertkey(5);
    h.insertkey(4);
    h.insertkey(45);
    h.insertkey(35);
    h.insertkey(46);
    h.insertkey(21);
    h.insertkey(98);
   // cout << h.extract_max() << " ";
   // cout << h.get_max() << " ";
    h.increase_key(2,50);
 //   cout << h.get_max();
    for(int i=0;i<11;i++)
        cout << h.extract_max() << endl;
    return 0;
}

