#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}*root;

/*int maxi(int a , int b)
{
    //cout << "hello5" << endl;
    if(a>b)
        return a;
    else
        return b;
}*/

class avl
{
public:


    //Height
    int height(Node *temp)
    {
        int h=0;
        if(temp!=NULL)
        {
            cout << "hello6" << endl;
            int lheight=height(temp->left);
            int rheight=height(temp->right);
            int max_height=max(lheight,rheight);
            h=max_height+1;
        }
        return h;
    }

    //Balanced Factor
    int diff(Node *temp)
    {
            int lheight=height(temp->left);
            int rheight=height(temp->right);
            int dife=lheight-rheight;
        return dife;
    }

    //Right right rotation
    Node* rr_rotation(Node *parent)
    {
        Node *temp=parent->right;
        parent->right=temp->left;
        temp->left=parent;
        return temp;
    }

    //Left left rotation
    Node* ll_rotation(Node *parent)
    {
        Node *temp=parent->left;
        parent->left=temp->right;
        temp->right=parent;
        return temp;
    }

    //Left right rotation
    Node* lr_rotation(Node *parent)
    {
        Node *temp=parent->left;
        parent->left=rr_rotation(temp);
        return ll_rotation(parent);
    }

    //Right left rotation
    Node* rl_rotation(Node *parent)
    {
        Node *temp=parent->right;
        parent->right=ll_rotation(temp);
        return rr_rotation(parent);
    }

    Node* balance(Node *temp)
    {
        cout << "hello4" << endl;
        int bal_fact=diff(temp);
        cout << bal_fact << endl;
        if(bal_fact > 1)
        {
            if(diff(temp->left)>0)
            {
                temp=ll_rotation(temp);
            }
            else
                temp=lr_rotation(temp);
        }
        else if(bal_fact < -1)
        {
            if(diff(temp->right)>0)
            {
                temp=rl_rotation(temp);
            }
            else
                temp=rr_rotation(temp);
        }
        return temp;
    }

    Node* insert(Node *root,int value)
    {
        if (root == NULL)
        {
            root = new Node;
            root->data = value;
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        //cout << "hello1" << endl;
        else if(root->data > value)
        {
            cout << "hello2" << endl;
            root->left=insert(root->left,value);
            cout << "hello3" << endl;
            root = balance (root);
            cout << "hello4" << endl;
        }
        else if(root->data <= value)
        {
            root->right=insert(root->right,value);
            root = balance (root);
        }
        return root;
    }


    void preOrder(Node* root)
    {
        if (root)
        {
            preOrder(root->left);
            cout<<root->data<<" ";
            preOrder(root->right);
        }
    }

    avl()
        {
            root = NULL;
        }
};


int main()
{
    int choice, item,c=1;
    avl avlq;
    while (c)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.PreOrder traversal"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avlq.insert(root, item);
            break;
        case 2:
            cout<<"Preorder Traversal:"<<endl;
            avlq.preOrder(root);
            cout<<endl;
            break;
        case 3:
            c=0;
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
