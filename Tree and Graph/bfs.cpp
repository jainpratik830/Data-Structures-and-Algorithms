#include<iostream>

using namespace std;

int front=0;
class node
{
public:
    int data;
    node* left, *right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

node *root=NULL,*x=NULL;

class queue
{
public:
    int front=-1,rear=0;
    node* a[100];
    void enqueue(node* b)
    {
        if(front==-1)
            front++;
        a[rear]=b;
        rear++;
    }
    void dequeue()
    {
        if(rear !=0)
        {
            for(int i=0;i<rear-1;i++)
            a[i]=a[i+1];
        rear--;
    }
    }
    int isEmpty()
    {
        if(rear==0)
            return 1;
        else
        return 0;
    }

};

queue q1,q2;
void bfs(node *v)
{
    int c=1;
    q2.enqueue(v);
    while(c)
    {

    if(v->left==NULL && v->right==NULL)
    {
   //     cout << "Hello2" << "   " << q1.isEmpty() << endl;


        if(q1.isEmpty())
            return;
    //    cout << q1.a[front]->data << endl;
        x=q1.a[front];
        q1.dequeue();
        bfs(x);

    }
    else
    {
       // cout << "Hello1" << endl;

        if(v->left!=NULL && v->right!=NULL)
            {
                 q1.enqueue(v->left);
                 q1.enqueue(v->right);
            }
        else if(v->left==NULL && v->right!=NULL)
            q1.enqueue(v->right);
        else if(v->left!=NULL && v->right!=NULL)
            q1.enqueue(v->left);
        x=q1.a[front];
        q1.dequeue();
        bfs(x);
        return;
    }
    }
}

void display()
{
    cout << q2.rear;
    for(int i=0;i<q2.rear;i++)
        cout << q2.a[i]->data << "    ";
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);
    bfs(root);
    display();
}
