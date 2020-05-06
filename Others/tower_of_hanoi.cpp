#include<iostream>
using namespace std;
int count=0;
void toh(int n,char src,char aux,char dest)
{

	if (n>0)
	{	toh(n-1,src,dest,aux);
		count++;
		cout<<count << " Moving disc "<< src<< " to " << dest <<endl;
		toh(n-1,aux,src,dest);

	}
};
int main()
{
 int a;
 cout <<"Enter number of discs: ";
 cin>> a;
 cout << endl;
 toh(a,'A','B','C');
 return 0;
}

