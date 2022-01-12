#include<stdio.h>
#include<stdlib.h>


// PROGRAM TO SWAP THE FIRST AND LAST NODE BY SWAPPING NODE DATA

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);
void move(node*);

int main(void)
{
    start=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    save->link=NULL;
    start=save;

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

    printf("\n\nthis is your linked list....\n\n");

    display(start);

    move(start);

    save=start;

    node*prv;

    prv=save;
    while(save!=NULL)
    {
        save=save->link;
        free(prv);
        prv=save;
    }

    return 0;
}

void insert(node*s)
{
    int data;

    printf("\nenter node data: ");
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

    printf("NULL\n");
}


void move(node*s)
{
    node*i=s;

    while(i->link!=NULL)
    {
        i=i->link;
    }

    int temp;

    temp=s->data;
    s->data=i->data;
    i->data=temp;

    printf("\n\nthis is your linked list after swapping the first and last node's data:\n\n");

    display(s);


}