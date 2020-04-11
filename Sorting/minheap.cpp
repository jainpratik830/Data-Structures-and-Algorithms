#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *leftchild, *rightchild;

};

node *root;

struct node *search(int data)
{
 	while(root->data != data)
 	{
 		if(root->leftchild==NULL && root->rightchild==NULL && root->data!=data)
 			return 0;
 		else
 		{
 			if(root->data>data)
 				root=root->leftchild;
 			else
 				root=root->rightchild;
 		}
 	}
 	return root;
 }

node* insert(node *root,int data)
 {
 	struct node *temp=new node;
 	struct node *parent;
 	struct node *current;

 	temp->data=data;
 	temp->leftchild=NULL;
 	temp->rightchild=NULL;

 	if (root==NULL){

 		root=temp;
 		cout<< "\nAdding data to root";
 		return root;
 	}
 	else
 	{
 		/*current=root;
 		parent=NULL;
 		while(1)
 		{
			parent=current;
			if(a>parent->data)
			{
				current=current->leftchild;
				if(current== NULL)
				{
					parent->leftchild=temp;
					return;
				}
				current=current->rightchild;
				if(current== NULL)
				{
					parent->rightchild=temp;
					return;
				}
			}
			else
			{
				current=current->rightchild;
				if(current== NULL)
				{
					parent->rightchild=temp;
					return;
				}
			}
		}
	} */
	if (data > root->data)
    {
            if(root->leftchild != NULL && root->rightchild != NULL && data > root->leftchild->data)
        {
            root=insert(root->leftchild, data);
            cout<<"\nhello2:Here data is going down";
        }
        if(root->leftchild != NULL && root->rightchild == NULL)
        {
            root=insert(root->rightchild, data);
            cout<<"\nhello3:Here data is going right";
        }
         if(root->leftchild == NULL)
        {
            root=insert(root->leftchild, data);
            cout<<"\nhello4:Here data is going left";
        }
    }


    else
    {
        cout<<"\nhello5::Here data is less than root";
       int c=root->data;
       root->data=data;
       root=insert(root,c);
    }
    }
}

void inorder(struct node *node)
{
	if(node==NULL)
	{
		return;
	}
	else{
		inorder(node->leftchild);
		cout << node->data << " ";
		inorder(node->rightchild);
		}


}


int main()
{
	cout << "hi";
	root=NULL;
	root=insert(root,50);
		cout<<root->data << "=rooot";
 	    insert(root,30);
         cout<<root->data << "=rooot" ;
    	insert(root,20);
         cout<<root->data << "=rooot" ;
    	insert(root,40);
    	insert(root,70);
    	insert(root,60);
    	insert(root,80);
    	insert(root,15);
    	insert(root,75);
    	insert(root,98);
    	inorder(root);
    	//cout << bool(search(76));
    	return 0;

}






