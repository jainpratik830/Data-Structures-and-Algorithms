#include<iostream>
using namespace std;

class edge{
public:
    int sour;
    int dest;
    int weight;
};

    edge *neigh=new edge[10];

edge findSmallestElement(edge arr[],int e){
   edge temp = arr[0];
   int p=0;
 //  cout<< temp.weight<<endl;
      for(int i=0; i<e; i++)
    {

      if(temp.weight>arr[i].weight)
        {
         temp=arr[i];
         p=i;
        }
   }
//   cout <<p<<"      "<< endl << arr[p].sour<<"   "<<arr[p].dest;
   arr[p].weight=INT_MAX;
//cout<< arr[p].weight;
   return temp;
}
int neighbour(int a,int b,int e,int n,edge *input)
{


    int k=0,l=0;
    for(int i=0;i<e;i++)
    {
        if(a==input[i].sour || b==input[i].sour || a==input[i].dest || b==input[i].dest  )
            {
                k++;
            }
    }
    for(int i=0;i<e;i++)
    {
        if(a==input[i].sour || b==input[i].sour|| a==input[i].dest || b==input[i].dest)
            {
                neigh[l]=input[i];
      //          cout << neigh[l].sour << "   " << neigh[l].dest<<neigh[l].weight<<endl;
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
    int parent[n];

    for(int i=0;i<v;i++)
        parent[i]=i;
    int count=0;
    edge currentedge=findSmallestElement(input,e);
  //  cout<< parent[2]<<endl;
    //cout << "hello1\n";
    output[count]=currentedge;
    int sourparent=findparent(currentedge.sour,parent);
    int destparent=findparent(currentedge.dest,parent);
    parent[sourparent]=destparent;
    //cout << "hello2\n";
    count++;

    while(count !=n)
    {
        int k=0;
   //     cout << currentedge.sour << "   " << currentedge.dest;

        k=neighbour(currentedge.sour,currentedge.dest,e,v-1,input);
        edge lastedge=currentedge;
        edge currentedge=findSmallestElement(neigh,k);
        //cout << "hello3\n"<<k<<endl;

        //edge currentedge=findSmallestElement(neigh,k);
        //cout << "hello5\n";
    //    cout << currentedge.sour << "   " << currentedge.dest;
        sourparent=findparent(currentedge.sour,parent);
         //           cout << "hello7\n";
//cout <<sourparent;
        destparent=findparent(currentedge.dest,parent);
         //   cout << "hello8\n";
//cout <<destparent;
        if(sourparent!=destparent)
        {
          //  cout << "hello4\n";
            output[count]=currentedge;
            count++;
            parent[sourparent]=destparent;
        }
        else
        {
           // cout << "hello6\n";
            currentedge=lastedge;
        }
    }

    for(int i=0;i<n;i++)
    {
     //  cout << "hello5\n";
        if(output[i].sour<output[i].dest)
        {
            cout << output[i].sour<< "   " << output[i].dest << "   " <<output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << "   " << output[i].sour << "   " <<output[i].weight << endl;
        }
    }

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

    prism(input ,v ,e);
    return 0;
}

