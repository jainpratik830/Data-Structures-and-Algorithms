#include<iostream>
using namespace std;

class edge{
public:
    int sour;
    int dest;
    int weight;
};


int findparent(int v, int *parent)
{
    if(parent[v]==v)
        return v;
    else
        return findparent(parent[v],parent);
}

krushals(edge *input,int v,int e)
{
    int n=v-1;
    for (int i=1;i<e;i++)
    {
        edge temp=input[i];
        int j=i-1;
        while(j>=0 && input[j].weight>temp.weight)
        {
            input[j+1]=input[j];
            j=j-1;
        }
        input[j+1]=temp;
    }
    edge *output =new edge[n];
    int *parent=new int[n];
    for(int i=0;i<=n;i++)
        parent[i]=i;

    int count=0,i=0;
    while(count !=n)
    {
        edge currentedge=input[i];
        int sourparent=findparent(currentedge.sour,parent);
        int destparent=findparent(currentedge.dest,parent);

        if(sourparent!=destparent)
        {
            output[count]=currentedge;
            count++;
            parent[sourparent]=destparent;
        }
        i++;
    }

    cout << "The minimum spanning tree is:" << endl;
    for(int i=0;i<n;i++)
            cout << output[i].dest << "   " << output[i].sour << "   " <<output[i].weight << endl;

}

int main()
{
    int v,e;
    cin >> v >> e;
    int n=v-1;
    edge *input=new edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        input[i].sour=s;
        input[i].dest=d;
        input[i].weight=w;
    }

    krushals(input ,v ,e);
}
