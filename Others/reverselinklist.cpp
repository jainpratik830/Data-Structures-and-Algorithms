#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	};
struct node *head=NULL;

void reverse()
{
    node *current=head;
    node *prev=NULL,*next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void insertstart(int a)
{
	node *newnode=new node;
	newnode->data=a;
	newnode->next=head;
	head=newnode;

}
void insertend(int a)
{
	node* r=head;
	while(r->next !=NULL)
       r=r->next;
	struct node *newnode=new node;
	newnode->data=a;
	newnode->next=NULL;
	r->next=newnode;
}

void insertposition(int a,int b)
{
	node* r=head;
	node* s;
	int n=1;
	while(n != b){
        r=r->next;
        n++;
	}
	s=r->next;
	struct node *newnode=new node;
	newnode->data=a;
	newnode->next=s;
	r->next=newnode;
}

void display()
{
	if(head==NULL)
	cout<< "list is empty" << endl;
	else
	{
		struct node *temp=head;
		while(temp!=NULL)
		{
			cout << temp->data << endl;
			temp=temp->next;
		}
	}
}

int del(int b)
{
    int x=0;
	if(head==NULL){
	cout<< "list is empty" << endl;
	return 0;
	}
	else
	{
		node* r=head;
	node* s;
	int n=1;
	while(n+1 != b){
        r=r->next;
        n++;
	}
	s=r->next->next;
	x=r->next->data;
	r->next=s;
	}
	return x;
}

int main()
{
	int b,c=1,d;
	do{
        int ch;
        cout<<"Enter choice:\n 1.Insert at Start\n 2.Insert at End\n 3.Insert at position\n 4.Delete\n 5.Display\n 6.Reverse\n 7.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter Data ";
                cin>>b;
                insertstart(b);
                break;
            case 2:
                cout<<"Enter Data ";
                cin>>b;
                insertend(b);
                break;
            case 3:
                cout<<"Enter Data "<<endl;
                cin>>b;
                cout << "Enter the postion to insert at ";
                cin>>d;
                cout << endl;
              	insertposition(b,d);
                break;
            case 4:
                cout << "Enter the postion to delete at ";
                cin >> d;
                cout << endl << "Deleting " << del(d) <<endl;
                break;
            case 5:
                display();
                break;
            case 6:
                reverse();
                break;
            case 7:
                c = 5;
                break;
        }

    }while(c==1);

}






