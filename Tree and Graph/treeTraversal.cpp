#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
class stack
{
public:
    int t=0;
    Node *a[100];
   void push(Node* data)
   {
        if(t==100)
		cout << "Stack is Full"<< endl;
        else
	{
        a[t]=data;
        t++;
	}
    }

    Node* pop()
    {
        Node* k=a[t-1];
        if(t==0)
            {
            cout << "ERRROR:Stack is empty"<< endl;
            return 0;
            }
        else
        {
            t--;
            return k;
        }

    }

    bool isempty()
    {
        return t;
    }

    void display()
    {
	if(t==0)
		cout << "Stack is empty"<< endl;
	else
	{
		for (int i=0;i<t;i++)
			cout<< a[i]->data << endl;
	}
    }
};

stack s,s1;

void preOrder(Node* root){
   /* if (root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }*/
    Node *current=root;
    s1.push(current);
    while(s1.isempty())
    {
        current=s1.a[s1.t-1];
        s1.pop();
        cout << current -> data << "   ";
        if(current->right)
            s1.push(current->right);
        if(current->left)
            s1.push(current->left);


    }

}

void inOrder(Node* root){
   /* if (root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }*/
    Node *current=root;
    while(current != NULL || s.isempty() )
    {
        while(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        current=s.a[s.t-1];
        s.pop();
        cout << current->data<< "   ";
        current=current->right;
    }
}

void postOrder(Node* root){
    if (root){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
}

