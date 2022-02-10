#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

node*newNode(node*);
node*insert(node*);
void display(node*);
void sort(node*);
void terminate(node*);
node*insertNode(node*, int);

int main(void)
{
    char ans='y';
    node*head1=NULL;

    printf("\n\nenter elements into the linked list....\n\n");

    while(ans=='y' || ans=='Y')
    {
        head1=insert(head1);


        printf("\ndo you want to enter more?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your linked list.....\n\n");

    display(head1);
    sort(head1);
    printf("\n\nthis is your linked list after sorting it....\n\n");
    display(head1);
    printf("\n\n\n");
    int value;

    printf("enter value to be inserted into the list......\n\n");
    scanf("%d", &value);

    head1=insertNode(head1, value);

    printf("\n\nthis is your new linked list....\n\n");

    display(head1);

    terminate(head1);

    return 0;
}

node*newNode(node*h)
{
    int data;

    printf("\nenter node data: ");
    scanf("%d", &data);

    h=(node*)malloc(sizeof(node));
    h->data=data;
    h->link=NULL;
    return h;
}

node*insert(node*h)
{
    if(h==NULL)
        return newNode(h);

    h->link=insert(h->link);
    return h;
}

void display(node*h)
{
    while(h!=NULL)
    {
        printf("%d->", h->data);
        h=h->link;
    }
}


void sort(node*h)
{
    int temp;
    node*i=h, *j=NULL;

    while(i!=NULL)
    {
        j=h;
        while(j->link!=NULL)
        {
            if(j->data > j->link->data)
            {
                temp=j->data;
                j->data=j->link->data;
                j->link->data=temp;
            }

            j=j->link;
        }

        i=i->link;
    }
}

node*insertNode(node*h, int value)
{
    if(h==NULL)  // if the element to be inserted is greater than all the elements in the list
    {
        h=(node*)malloc(sizeof(node));  // allocating memory for the new node to be inserted
        h->data=value;
        h->link=NULL;  // it's the last node, so .......
        return h;
    }

    else if(value < h->data)  // if the element to be inserted is smaller than the current node's value
    {
                            // remember that the list is sorted
        node*n;
        n=(node*)malloc(sizeof(node));  // allocating memory for the new node to be inserted
        n->data=value;
        n->link=h; // since the new node's value is smaller than the current node, it's gonna come before the current node
        return n;
    }

    h->link=insertNode(h->link, value);
    return h;
}

void terminate(node*h)
{
	node*s=h, *t=s;
	
	while(s!=NULL)
	{
		s=s->link;
		free(t);
		t=s;
	}
}
