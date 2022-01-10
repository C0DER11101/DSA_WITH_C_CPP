#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

node*start,*save,*next;

// PROGRAM TO FIND THE LARGEST AND SMALLEST ELEMENT IN A LINKED LIST.....


void insert(node*);
void display(node*);
void dig(node*); // dig out the largest and smalles element from the list XD

void main(void)
{
    start=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    start=save;
    start->link=NULL;
    char ans;

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

    dig(start);

    save=start;

    free(save);

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

void dig(node*s)
{
    node*i=s;
    int large=s->data, small=s->data;

    while(i!=NULL)
    {
        if(i->data<small)
        {
            small=i->data;
        }

        i=i->link;
    }

    i=s;

    while(i!=NULL)
    {
        if(i->data>large)
        {
            large=i->data;
        }

        i=i->link;
    }

    printf("\nLargest element in the list is >>> %d\n", large);
    printf("\nSmallest element in the list is >>> %d\n", small);


}