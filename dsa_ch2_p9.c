#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO  MOVE THE LARGEST ELEMENT TO THE END OF A LINKED LIST.....

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);
node* move(node*);

void main(void)
{
    char ans;
    start=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    save->link=NULL;
    start=save;
    printf("\ndo you want to continue?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        insert(next);
        save->link=next;
        save=next;
        next->link=NULL;

        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your linked list....\n\n");

    display(start);

    start=move(start);

    printf("\n\nthis is your linked list after moving the largest node to the end....\n\n");

    display(start);

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
    while(s!=NULL)
    {
        printf("%d->", s->data);
        s=s->link;
    }

    printf("NULL\n\n");
}

node* move(node*s)
{
    node*i=NULL, *lnode=NULL;

    i=s;
    int large=0;

    while(i!=NULL) // searching for the largest element in the list
    {
        if(i->data > large)
        {
            large=i->data;
        }

        lnode=i;
        i=i->link;
    }

    /* now we will compare each element with the largest element*/

    i=s;
    node*prev=NULL, *adv=NULL;

    while(i!=NULL)
    {
        if(i->data == large)
        {
            break;
        }

        prev=i;
        i=i->link;        
    }

    if(i==s)
    {
        lnode->link=i;
        s=i->link;
        i->link=NULL;
    }

    else if(i->link==NULL)
    {
        return s;
    }

    else
    {
        prev->link=i->link;
        lnode->link=i;
        i->link=NULL;
    }

    return s;
}