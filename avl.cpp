#include<iostream>
#include<stdlib.h>

// PERFECTLY WORKING CODE FOR AVL TREE!!!!!
// DELETION, INSERTION PERFORMED NICELY: ROTATIONS PERFORMED NICELY!!!!

/* REVIEW THE DELETION CODE FOR THE AVL TREE, AND RUN THE CODE!!! THE BALANCE FACTORS OF THE DELETED NODES HAVE NOT YET BEEN
 * CALCULATED!!!!
*/

/* READ THIS BEFORE PROCEEDING FURTHER FOR DELETION
 * after deletion of a node just call blntree(node*); which will traverse the whole tree and in the unwinding phase, it will perform
 * functions similar to insert() function (like calling bf() and checkBalance())
*/

/* DELETION IN AVL TREE HAS TO BE DONE SOMEWHAT LIKE DELETION IN BST(ALONG WITH ROTATIONS)
   THE FOLLOWING CASES OF BST WILL BE USED:
   -> NODE TO BE DELETED HAS ONE CHILD(LEFT OR RIGHT)
   -> NODE TO BE DELETED HAS TWO CHILDREN : SEARCH FOR INORDER SUCCESSOR

   ROTATIONS WILL BE DONE ACCORDING TO THE VALUES OF BALANCE FACTORS OF THE NODES
*/

// PERFECTLY WORKING CODE FOR INSERTION IN AVL TREE(PERFORMS ROTATIONS AS WELL)

/*
   INSERTION DONE IN LEFT SUBTREE:
   -> NODE WAS INSERTED IN THE LEFT SUBTREE OF THIS SUBTREE - perform right rotation about node p
   -> NODE WAS INSERTED IN THE RIGHT SUBTREE OF THIS SUBTREE - perform leftright rotation

   INSERTION DONE IN RIGHT SUBTREE:
   -> NODE WAS INSERTED IN THE RIGHT SUBTREE OF THIS SUBTREE - perform left rotation about p
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
node*searchPar(node*, node*); // search the parent of the current node(if any)
node*searchInorder(node*); // search the inorder successor of the node to be deleted
node*searchNode(node*, int); // search a node
int checkChildren(node*);
void checkDelBln(node**); // check the balance factor of a node after deletion of a node from that subtree!!!
void preorder(node*);
void inorder(node*);
void postorder(node*);
int blntree(node*); // to calculate balance factors after deletion of nodes from the tree!!!
int bf(node*); // balance factor
int height(node*); // height of the tree
void checkBalance(node**);
void rotateRight(node*, node**);
void rotateLeft(node*, node**);
node*delNode(node*, node*); // to delete nodes, takes an int argument to see if the node to be deleted has one or two or no children!!!
void terminate(node*);


int main(void)
{
	int opt, key;
	node*foundNode=NULL;

	while(1)
	{
		cout<<"\n\n---menu---\n\n";
		cout<<"1. Insert.\n";
		cout<<"2. Calculate height.\n";
		cout<<"3. Search.\n";
		cout<<"4. Preorder.\n";
		cout<<"5. Inorder.\n";
		cout<<"6. Postorder.\n";
		cout<<"7. Delete.\n";
		cout<<"8. Exit.\n";

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
				cout<<"enter node to be searched: ";
				cin>>key;
				foundNode=searchNode(root, key);
				if(foundNode==NULL)
					cout<<foundNode->key<<" is in the tree!\n";
				else
					cout<<key<<" is not in the tree!\n";
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				inorder(root);
				break;
			case 6:
				postorder(root);
				break;
			case 7:
				cout<<"enter node to be deleted: ";
				cin>>key;
                                foundNode=searchNode(root, key);
				if(foundNode==NULL)
                                {
					cout<<key<<" is not in the tree!!\n\n";
                                }
                                
                                else
                                {
                                        parent=searchPar(root, foundNode);
                                       root=delNode(parent, foundNode); // delete foundNode
                                }
				break;
			case 8:
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

node*searchNode(node*r, int key)
{
	while(r!=NULL)
	{
		if(r->key==key)
			break;
		else if(key<r->key)
			r=r->left;
		else if(key>r->key)
			r=r->right;
	}


	return r;

}

int checkChildren(node*r)
{
	if(r->left==NULL && r->right==NULL)
		return 0;
	else if(r->left==NULL && r->right!=NULL)
		return 1;
	else if(r->left!=NULL && r->right==NULL)
		return 1;
	else
		return 2;
}


node*searchInorder(node*n)
{
        n=n->right;
        
        while(n->left!=NULL)
                n=n->left;
        
        return n;
}

node* delNode(node*parent, node*child) // child will be deleted!!
{
        node*inorderS=NULL;
        if(checkChildren(child)==2) // if child has two children
        {
                inorderS=searchInorder(child);
                parent=searchPar(root, inorderS);
                /* since parent has no use with child so inorderS's parent will be searched*/
                child->key=inorderS->key; // copying the value of inorder successor into child
                
                if(checkChildren(inorderS)==1)
                        parent->left==inorderS?parent->left=inorderS->right:parent->right=inorderS->right;
                
                else
                        parent->left==inorderS?parent->left=NULL:parent->right=NULL;
                
                delete inorderS; // inorder successor is deleted!!!
                blntree(root); // call checkBalance() in this function
        }
        
        else if(checkChildren(child)==1) // if child has one child
        {
                if(parent->left==child)
                {
                        if(child->right!=NULL)
                        {
                                parent->left=child->right;
                        }
                        
                        else
                        {
                                parent->left=child->left;
                        }
                }
                
                else
                {
                        if(child->right!=NULL)
                        {
                                parent->right=child->right;
                        }
                        
                        else
                        {
                                parent->right=child->left;
                        }
                }
                
                delete child;
                blntree(root);
        }
        
        else // if child has no children
        {
                if(parent->left==child)
                        parent->left=NULL;
                else
                        parent->right=NULL;
                
                delete child;
                blntree(root);
        }
        
        return root;
}


int blntree(node*r)
{
        int hL, hR;
        if(r==NULL)
                return 0;
        hL=1+blntree(r->left);
        hR=1+blntree(r->right);
        
        r->balance=hL-hR;
        checkDelBln(&r);
        
        if(hL>hR)
                return hL;
        else
                return hR;
}

void checkDelBln(node**r)
{
        switch((*r)->balance)
        {
                case 2: // deletion was done from the right subtree
                        // similar to insertion in the left subtree
                        switch((*r)->left->balance)
                        {
                                case 0:
                                        // right rotation about node r
                                        parent=searchPar(root, (*r));
                                        rotateRight(parent, r);
                                        break;
                                case 1:
                                        // right rotation about node r
                                        parent=searchPar(root, (*r));
                                        rotateRight(parent, r);
                                        break;
                                case -1: // special case
                                        // leftright rotation
                                        a=(*r)->left;
                                        rotateLeft(*r, &a);
                                        parent=searchPar(root, (*r));
                                        rotateRight(parent, r);
                                        break;
                        }
                        
                        break;
                        
                case -2: // deletion was done from the left subtree
                         // similar to insertion in the right subtree
                        switch((*r)->right->balance)
                        {
                                case 0:
                                        // left rotation about node r
                                        parent=searchPar(root, (*r));
                                        rotateLeft(parent, r);
                                        break;
                                case -1:
                                        // left rotation about node r
                                        parent=searchPar(root, (*r));
                                        rotateLeft(parent, r);
                                        break;
                                case 1: // special case
                                        // rightleft rotation
                                        a=(*r)->right;
                                        rotateRight(*r, &a);
                                        parent=searchPar(root, (*r));
                                        rotateLeft(parent, r);
                                        break;
                        }
                        
                        break;
        }
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
					parent=searchPar(root, (*r));
					rotateRight(parent, r);
					break;

				case -1:
					// insertion was done in the right subtree of this subtree
					/*call a function to balance the unbalanced node*/
					a=(*r)->left;
					rotateLeft(*r, &a);
					parent=searchPar(root, (*r));
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
					parent=searchPar(root, (*r));
					rotateLeft(parent, r);
					break;

				case -1:
					// insertion was done in the right subtree of this subtree
					parent=searchPar(root, (*r));
					rotateLeft(parent, r);
					break;
			}
			break;

	}

	return;
}

node*searchPar(node*r, node*n)
{
	if(r->key==n->key)
		return r;
	while(r!=NULL)
	{
		if(r->left->key==n->key || r->right->key==n->key)
			return r;
		else if(n->key<r->key)
			r=r->left;
		else if(n->key>r->key)
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
