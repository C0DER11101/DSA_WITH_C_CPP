#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO SWAP ADJACENT ELEMENTS OF A LINKED LIST BY EXCHANGING NODES

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);
void swap(node*);

void main(void)
{
    start=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    start=save;
    save->link=NULL;

    char ans;

    printf("\ndo you want to continue?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        insert(next);
        save->link=next;
        next->link=NULL;
        save=next;

        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your linked list.....\n\n");

    display(start);

    swap(start);

    save=start;
    node*prev;
    prev=save;
    while(save!=NULL)
    {
        save=save->link;
        free(prev);
        prev=save;
    }


}

void insert(node*s)
{
    int data;
    printf("enter node data: ");
    scanf("%d", &data);
    s->data=data;
}

void display(node*s)
{
    while(s!=NULL)
    {
        printf("%d->", s->data);
        s=s->link;
    }

    printf("NULL\n\n");
}

void swap(node*s)
{
    node*i=NULL, *j=NULL, *temp=NULL, *adv=NULL;

    i=s;
    j=i;

    while(i!=NULL)  // if the list contains even number of nodes
    {
        if(i->link==NULL)  // if the list contains odd number of nodes
        {
            break;
        }
        if(i==s)
        {
            adv=i->link;
            temp=i;
            i=adv;
            adv=temp;
            adv->link=i->link;
            i->link=adv;
            s=i;
        }

        else
        {
            adv=i->link;
            temp=i;
            i=adv;
            adv=temp;
            j->link=i;
            adv->link=i->link;
            i->link=adv;
        }

        j=i->link;  // storing the previous node of ith node
        i=i->link->link;
    }

    printf("\n\nthis is the list after swapping the adjacent elements......\n\n");
    display(s);


}