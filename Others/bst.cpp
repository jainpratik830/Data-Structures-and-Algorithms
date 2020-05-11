#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *left,*right;
};

node* root=NULL;


node* insert(node *root,int data)
{
   // cout<<"\nhello6";
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
  //  cout<<"\nhello7";
    if(root==NULL)
    {
     //   cout<<"\nhello1";
        root=temp;
  //      cout << root->data;
    }
    else
    {
    //    cout<<"\nhello5";
        node *head;
        head=root;
        int c=1;
        while(c)
    {
        if(temp->data<=head->data)
        {
            if(head->left==NULL){
  //                  cout<<"\nhello2"<<endl;
                head->left=temp;
                 c=0;
            }
            else
               {
                   head=head->left;


               }
        }
        else
        {
            if(head->right==NULL){
 //                   cout<<"\nhello3"<<endl;
                head->right=temp;
                 c=0;
            }
            else
               {
                   head=head->right;
     //              cout<<"\nhello4";
               }
        }
    }

    }
   // cout <<root->data;
    return root;
}

void inOrder(node *root)
{
    if (root!=NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    else return;
}

bool search(node *root,int a)
{
    node *head;
    head=root;
    int c=1;
    while(!(head->left==NULL && head->right==NULL))
    {
        if(a<=head->data)
        {
            if(a==head->data)
                return true;
            else
            {
                head=head->left;
            }
        }
        else
        {
                head=head->right;
        }
    }
    if(a==head->data)
        return true;
    return false;
}
node* findMin(node*root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* Delete(node *current,node *parent,int value)
{
	if(current==NULL)
		return current;
	else if(value< current->data)
	{
		parent=current;
		current= Delete(current->left,parent,value);
	}
	else if(value> current->data)
	{
		parent=current;
		current= Delete(current->right,parent,value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(current->left==NULL&&current->right==NULL)
		{

			if(current==parent->left)
            {
                parent->left=NULL;
//                free(current->data);
            }
            else
            {
                parent->right=NULL;
       //         free(current);
            }
		}
		//case 2: one child
		else if(current->left==NULL)
		{
			if(current==parent->left)
            {
                parent->left=current->right;
          //      free(current);
            }
            else
            {
                parent->right=current->right;
              //  free(current);
            }
		}
		else if(current->right==NULL)
		{
			if(current==parent->left)
            {
                parent->left=current->left;
          //      free(current);
            }
            else
            {
                parent->right=current->left;
           //     free(current);
            }
		}
		//case 3: 2 child
		else
		{
			node *temp=findMin(current->right);
			cout<< temp->data << endl;
			//if(current==parent->left)
         //   {
                //temp->left=current->left;
         //       current->data=temp->data;
	//		current->right=Delete(current->right,parent,temp->data);
          //      free(current);
        //    }
        //    else
        //    {
               int x=temp->data;
               Delete(root,root,temp->data);
                current->data=x;
		//
           //     free(current);
         //   }

		}
	}
	return current;
}
void preOrder(node* root){
   if (root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    root=insert(root,50);
    insert(root,30);
    insert(root,60);
    insert(root,10);
    insert(root,55);
    insert(root,70);
    insert(root,20);
    insert(root,90);
    insert(root,80);

    insert(root,95);
//  insert(root,65);
    preOrder(root);
  //  cout << search(root,97)<<endl;
  cout<< endl;
    Delete(root,root,60);
    preOrder(root);
}
