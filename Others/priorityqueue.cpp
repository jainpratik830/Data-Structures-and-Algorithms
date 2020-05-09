#include<iostream>
using namespace std;

struct node{
    int data;
    int priority;
    struct node *link;
};

node *frot=NULL;
node *rear=NULL;

void inset(int a,int b)
{
    node *temp=new node;;
    temp->data=a;
    temp->priority=b;
    if( frot==NULL || b<frot->priority)
    {
        temp->link=frot;
        frot=temp;
    }
    else
    {
        node *q=new node;;
        q=frot;
        while(q->link!= NULL && b>=q->link->priority)
            q=q->link;
        temp->link=q->link;
        q->link=temp;
    }
}

void del()
{
    node *temp=new node;;
    if(frot ==NULL)
        cout << "Queue Underflow\n";
    else
    {
        temp=frot;
        cout<< "Deleted item is " << temp->data << endl;
        frot =temp->link;
    }
}

void display()
{
     node *temp=new node;;
     temp=frot;
     cout <<" Data              Priority "<< endl;
     while(temp!=NULL)
     {
        cout << "   " << temp->data << "                " << temp->priority << endl;
        temp=temp->link;
     }
}

int main()
{
	int choice,i,p;
	do
	{
		cout<< "1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Display\n";
		cout<<"4.Quit\n";
		cout<<"Enter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
                cout<<"Input the item value to be added in the queue : ";
				cout<<"Enter its priority : ";
				cin>>p;
				cout<<"Enter the item : ";
				cin>>i;
				inset(i,p);
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
			break;
				default :
				cout<<"Wrong choice\n";
		}
	}while(choice!=4);

	return 0;
}
