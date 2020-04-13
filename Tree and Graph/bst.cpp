#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

Node* insert(Node* root, int data){
    if (root == NULL)
    {
        cout<<"\nhello8";
        root->data = data;
        cout<<root->data;
    root->right = root->left = NULL;
    }
    if (data > root->data)
    {
        cout<<"\nhello1";
        if(root->left != NULL && root->right != NULL && data > root->left->data)
        {
            insert(root->left, data);
            cout<<"\nhello2";
        }
        if(root->left != NULL && root->right == NULL)
        {
            insert(root->right, data);
            cout<<"\nhello3";
        }
         if(root->left == NULL)
        {
            insert(root->left, data);
            cout<<"/nhello4";
        }
    }

    else
    {
        cout<<"/nhello5";
       int c=root->data;
       root->data=data;
       insert(root,c);

    }
    return root;
}

void preOrder(Node* root){
    if (root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    else return;
}

void inOrder(Node* root){
    if (root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    else return;
}

void postOrder(Node* root){
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
    else return;
}

int main(){
    Node* root = NULL;
    root=insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
}
