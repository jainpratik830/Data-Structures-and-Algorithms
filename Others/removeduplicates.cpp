#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	};
struct node *head=NULL;

void insertstart(int a)
{

	node *newnode=new node;
	newnode->data=a;
	newnode->next=head;
	head=newnode;


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
void removeduplicate()
{
    node *r=head;
    node *s=head;
    node *p=head;
    int n=1;
    while(p!= NULL)
    {
        n=n+1;
        r=s;
        while(s->next!= NULL && s->data==s->next->data)
        {
            del(n);
        }
        p=p->next;
        s=s->next;
    }
}

int main()
{
	int b,c=1,d;
	do{
        int ch;
        cout<<"Enter choice:\n 1.Insert\n 2.Remove Duplicates\n 3.Delete\n 4.Display\n 5.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter Data ";
                cin>>b;
                insertstart(b);
                break;
            case 2:
                removeduplicate();
                break;
            case 3:
                cout << "Enter the postion to delete at ";
                cin >> d;
                cout << endl << "Deleting " << del(d) <<endl;
                break;
            case 4:
                display();
                break;
            case 5:
                c = 5;
                break;
        }

    }while(c==1);

}
