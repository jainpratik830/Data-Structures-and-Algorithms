#include<iostream>
using namespace std;

class edge{
public:
    int sour;
    int dest;
    int weight;
};
int x=99999;
edge *neigh=new edge[100];
edge *input=new edge[100];
int k=0,l=0;


int findoriginal(int a,int b,edge *input,int e)
{
    for(int i=0;i<e;i++)
    {
        if(input[i].sour==a && input[i].dest==b)
           return i;
    }
}

edge findSmallestElement(edge *arr,int e,int edges){
     edge temp = arr[0];
     int p=0;
     for(int i=0; i<e; i++)
     {
      if(temp.weight>arr[i].weight)
        {
         temp=arr[i];
         p=i;
        }
    }
    int m=findoriginal(arr[p].sour,arr[p].dest,input,edges);
    for(int i=0;i<e;i++)
    {
        if(arr[i].sour==arr[p].sour && arr[i].dest==arr[p].dest)
           arr[i].weight=x;
    }

   input[m].weight=x;
   return temp;
}

int neighbour(int a,int b,int e,int n,edge *input)
{
    for(int i=0;i<e;i++)
    {
        if(a==input[i].sour || b==input[i].sour|| a==input[i].dest || b==input[i].dest)
            {
                neigh[l]=input[i];
                k++;
                l++;
            }
    }
    return k;

}

int findparent(int v, int *parent)
{
    if(parent[v]==v)
        return v;
    else
        return findparent(parent[v],parent);
}


void prism(edge *input,int v,int e)
{
    int n=v-1;
    edge *output =new edge[n];
    int *parent=new int[n];
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int count=0;
    edge currentedge=findSmallestElement(input,e,e);
    output[count]=currentedge;
    int sourparent=findparent(currentedge.sour,parent);
    int destparent=findparent(currentedge.dest,parent);
    parent[sourparent]=destparent;
    count++;

    while(count !=n)
    {
        int j=0;
        j=neighbour(currentedge.sour,currentedge.dest,e,v-1,input);
        edge lastedge=currentedge;
        currentedge=findSmallestElement(neigh,j,e);
        sourparent=findparent(currentedge.sour,parent);
        destparent=findparent(currentedge.dest,parent);
        if(sourparent!=destparent)
        {
            output[count]=currentedge;
            count++;
            parent[sourparent]=destparent;
        }
        else
            currentedge=lastedge;
    }

    cout << "The minimum spanning tree is:" << endl;
    for(int i=0;i<n;i++)
        cout << output[i].sour<< "   " << output[i].dest << "   " <<output[i].weight << endl;
}

int main()
{
    int v,e;
    cin >> v >> e;
    int n=v-1;
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        input[i].sour=s;
        input[i].dest=d;
        input[i].weight=w;
    }

    prism(input ,v ,e);
    return 0;
}
