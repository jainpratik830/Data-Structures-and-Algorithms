#include<iostream>
using namespace std;


void print(int **input,int v,int cv,bool* visited)
{
    cout << cv << "     ";
    visited[cv]=true;

    for(int i=0;i<v;i++)
    {
        if (i==cv)
            continue;
        if(input[i][cv]==1)
        {
            if(visited[i])
            {
                continue;
            }
            print(input,v,i,visited);
        }
    }
}


int main()
{
    int v,e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    int input[v][v];
    bool* visited=new bool[v];

    for(int i=0;i<v;i++)
        visited[i]=false;

    for(int i=0;i<v;i++)
    {
       // input[i]=new int[v];
            for(int j=0;j<v;j++)
                input[i][j]=0;
    }

    cout << endl<< "Enter the edges: "<< endl;

    for(int i=0;i<e;i++)
    {
        int so,de;
        cin >> so >> de;
        input[so][de]=1;
        input[de][so]=1;
    }


    print(input[v],v,0,visited);

}

