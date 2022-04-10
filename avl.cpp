#include<iostream> 
#include<stdlib.h>

// PERFECTECTLY WORKING CODE FOR INSERTION IN AVL TREE(PERFORMS ROTATIONS AS WELL)
/*
   INSERTION DONE IN LEFT SUBTREE:
   -> NODE WAS INSERTED IN THE LEFT SUBTREE OF THIS SUBTREE - perform right rotation about node p
   -> NODE WAS INSERTED IN THE RIGHT SUBTREE OF THIS SUBTREE - perform leftright rotation

   INSERTION DONE IN RIGHT SUBTREE:
   -> NODE WAS INSERTED IN THE RIGHT SUBTREE OF THIS SUBTREE - perform left rotation about p
   -> NODE WAS INSERTED IN THE LEFT SUBTREE OF THIS SUBTREE - perform right rotation
   -> NODE WAS INSERTED IN THE LEFT SUBTREE OF THIS SUBTREE - perform rightleft rotation
*/

using namespace std;

struct node
{
	int key;
	node*left;
	node*right;
	int balance;
};

node*root=NULL, *parent=NULL, *a=NULL;
node*insert(node*, int);
node*searchPar(node*, int);
void preorder(node*);
void inorder(node*);
void postorder(node*);
int bf(node*); // balance factor
int height(node*); // height of the tree
void checkBalance(node**);
void rotateRight(node*, node**);
void rotateLeft(node*, node**);
/*void deleteNode(parameters go here); // to delete nodes*/
void terminate(node*);


int main(void)
{
	int opt, key;

	while(1)
	{
		cout<<"\n\n---menu---\n\n";
		cout<<"1. Insert.\n";
		cout<<"2. Calculate height.\n";
		cout<<"3. Preorder.\n";
		cout<<"4. Inorder.\n";
		cout<<"5. Postorder.\n";
		cout<<"6. Delete.\n";
		cout<<"7. Exit.\n";

		cout<<"[OPTION]";
		cin>>opt;

		switch(opt)
		{
			case 1:
				cout<<"\nenter key: ";
				cin>>key;
				root=insert(root, key);
				break;
			case 2:
				cout<<"\nheight of the tree is: "<<height(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				inorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				/*left for later*/
				break;
			case 7:
				if(root==NULL)
					exit(0);
				else
					terminate(root);
				exit(0);
				break;
		}

	}

	return 0;
}

node*insert(node*r, int key)
{
	if(r==NULL)
	{
		r=new node;
		r->key=key;
		r->left=r->right=NULL;
		r->balance=0;
		return r;
	}

	else if(key<r->key)
	{
		r->left=insert(r->left, key);
		bf(r);
		checkBalance(&r);
	}

	else if(key>r->key)
	{
		r->right=insert(r->right, key);
		bf(r);
		checkBalance(&r);
	}

	return r;
}

void checkBalance(node**r)
{
	switch((*r)->balance)
	{
		case 2:
			// move to the left subtree
			switch((*r)->left->balance)
			{
				case 1:
					// insertion was done in the left subtree of this subtree
					/*call a function to balance the node p*/
					parent=searchPar(root, (*r)->key);
					rotateRight(parent, r);
					break;

				case -1:
					// insertion was done in the right subtree of this subtree
					/*call a function to balance the unbalanced node*/
					a=(*r)->left;
					rotateLeft(*r, &a);
					parent=searchPar(root, (*r)->key);
					rotateRight(parent, r);
					break;
			}
			break;

		case -2:
			// move to the right subtree
			switch((*r)->right->balance)
			{
				case 1:
					// insertion was done in the left subtree of this subtree
					a=(*r)->right;
					rotateRight(*r, &a);
					parent=searchPar(root, (*r)->key);
					rotateLeft(parent, r);
					break;

				case -1:
					// insertion was done in the right subtree of this subtree
					parent=searchPar(root, (*r)->key);
					rotateLeft(parent, r);
					break;
			}
			break;

	}

	return;
}

node*searchPar(node*r, int key)
{
	if(r->key==key)
		return r;
	while(r!=NULL)
	{
		if(r->left->key==key || r->right->key==key)
			return r;
		else if(key<r->key)
			r=r->left;
		else if(key>r->key)
			r=r->right;
	}

	return r;
}
int height(node*r)
{
	int hL, hR;
	if(r==NULL)
		return 0;
	hL=1+height(r->left);
	hR=1+height(r->right);

	if(hL>hR)
		return hL;
	else
		return hR;
}


int bf(node*r)
{
	int hL, hR;
	if(r==NULL)
		return 0;

	hL=1+bf(r->left);
	hR=1+bf(r->right);
	r->balance=hL-hR;

	if(hL>hR)
		return hL;
	else
		return hR;
}


void rotateRight(node*par, node**child)
{
	if(par==(*child))
	{
		node*temp=(*child)->left;
		if(temp->right==NULL)
		{
			temp->right=(*child);
			(*child)->left=NULL;
			(*child)=temp;
		}
		
		else
		{
			node*store=temp->right;
			temp->right=(*child);
			(*child)->left=store;
			(*child)=temp;
		}
	}

	else
	{
		if(par->left==(*child))
		{
			par->left=(*child)->left;
			node*temp=(*child)->left;

			if(temp->right==NULL)
			{
				temp->right=(*child);
				(*child)->left=NULL;
				(*child)=temp;
			}

			else
			{
				node*store=temp->right;
				temp->right=(*child);
				(*child)->left=store;
				(*child)=temp;
			}

		}
	

		else if(par->right==(*child))
		{
			par->right=(*child)->left;
			node*temp=(*child)->left;

			if(temp->right==NULL)
			{
				temp->right=(*child);
				(*child)->left=NULL;
				(*child)=temp;
			}

			else
			{
				node*store=temp->right;
				temp->right=(*child);
				(*child)->left=store;
				(*child)=temp;
			}
		}
	}
}


void rotateLeft(node*par, node**child)
{
	if(par==(*child))
	{
		node*temp=(*child)->right;

		if(temp->left==NULL)
		{
			temp->left=(*child);
			(*child)->right=NULL;
			(*child)=temp;
		}

		else
		{
			node*store=temp->left;
			temp->left=(*child);
			(*child)->right=store;
			(*child)=temp;
		}
	}

	else
	{
		if(par->left==(*child))
		{
			par->left=(*child)->right;
			node*temp=(*child)->right;

			if(temp->left==NULL)
			{
				temp->left=(*child);
				(*child)->right=NULL;
				(*child)=temp;
			}

			else
			{
				node*store=temp->left;
				temp->left=(*child);
				(*child)->right=store;
				(*child)=temp;
			}
		}

		else if(par->right==(*child))
		{
			par->right=(*child)->right;
			node*temp=(*child)->right;

			if(temp->left==NULL)
			{
				temp->left=(*child);
				(*child)->right=NULL;
				(*child)=temp;
			}

			else
			{
				node*store=temp->left;
				temp->left=(*child);
				(*child)->right=store;
				(*child)=temp;
			}
		}
	}

}


void preorder(node*root)
{
	if(root==NULL)
		return;

	cout<<root->key<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node*root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}

void postorder(node*root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<" ";
}

void terminate(node*root)
{
	if(root==NULL)
		return;

	terminate(root->left);
	terminate(root->right);
	delete root;
}
