#include<stdio.h>
#include<stdlib.h>


// PROGRAM TO SWAP ADJACENT ELEMENTS OF A DOUBLY LINKED LIST BY REARRANGING THE NODES!!!

struct node
{
    struct node *prev;
    int data;
    struct node*link;
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
    save->prev=NULL;
    save->link=NULL;

    start=save;

    char ans;

    printf("\ndo you want to continue?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        insert(next);
        next->prev=save;
        save->link=next;
        next->link=NULL;
        save=next;

        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\nthis is your double linked list.....\n\n");
    display(start);

    swap(start);

    save=start;

    node*prv;

    prv=save;

    while(save!=NULL)
    {
        save=save->link;
        free(prv);
        prv=save;
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
    printf("NULL<--");
    while(s->link!=NULL)
    {
        printf("%d<_-_->", s->data);

        s=s->link;
    }

    printf("%d-->NULL\n\n", s->data);

}


void swap(node*s)
{
    node*i=NULL, *j=NULL, *temp=NULL, *adv=NULL;

    i=s;

    while(i!=NULL)
    {
        if(i->link==NULL)
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
            i->link->prev=adv;
            
            i->prev=NULL;
            i->link=adv;
            adv->prev=i;

            s=i;
        }

        else
        {
            adv=i->link;

            if(adv->link==NULL)  // if there are even number of elements then execute this if conditional
            {
                j=i->prev;
                temp=i;
                i=adv;
                adv=temp;
                adv->link=i->link;
                i->link=adv;
                adv->prev=i;
                j->link=i;
                i->prev=j;
            }

            else
            {
                j=i->prev;
                temp=i;
                i=adv;
                adv=temp;
                adv->link=i->link;
                i->link->prev=adv;
                j->link=i;
                i->prev=j;
                i->link=adv;
                adv->prev=i;
            }
        }

        i=i->link->link;
    }

    printf("\n\nthis is the double linked list after swapping adjacent elements....\n\n");

    display(s);
}