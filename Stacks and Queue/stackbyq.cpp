#include<iostream>
using namespace std;
int a[100],b[100],front=-1,front1=-1,rear=0,rear1=0;

void enqueue(int element,int c[])
{
	if(c==a)
	{
		if(front==-1)
			front=0;
			c[rear]=element;
			rear++;
	}

	else
    {
		if(front1==-1)
			front1=0;
			c[rear1]=element;
			rear1++;
	}
}

int dequeue()
{
    if(front==rear)
    {
        while(front1!=rear1-1)
        {
             enqueue(b[0],a);
             for(int i=0;i<rear1-1;i++)
            {

                b[i]=b[i+1];
            }
             rear1--;
        }
        int k=b[front1];
       rear1--;
        return k;
    }
    else
    {
        while(front!=rear-1)
        {
            enqueue(a[0],b);
            for(int i=0;i<rear-1;i++)
            {

                a[i]=a[i+1];
            }
             rear--;
        }
        int k=a[front];
        rear--;
        return k;
    }
}



void display(int a[],int b[])
{
	if(rear==0)
    {
		for (int i=rear1-1;i>=0;i--)
        cout<< b[i] << endl;
	}
	else
	{
		for (int i=rear-1;i>=0;i--)
        cout<< a[i] << endl;
	}
}

int main()
{
;
    int u,element;
    do{
	cout <<endl << "Choose: 1.Insert 2.Delete 3.display 4.Exit " << endl<< endl;
	cin >> u;
	switch (u)
	{
		case 1:
		cout << "enter the element to insert: "<< endl;
		cin >> element;
		if(rear1==0) enqueue(element,a);
		else    enqueue(element,b);
		break;
		case 2:
		cout << "Deleting the 1st element i.e. " << dequeue() <<endl;
		break;
		case 3:
	    display(a,b);
		break;
		case 4:
		cout << "Exitting"<< endl;
		defaut:
		cout <<"Please enter a valid choice "<< endl;
		break;
	}
	}while(u!=4);

}

