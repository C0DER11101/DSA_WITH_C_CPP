#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO MOVE THE SMALLEST ELEMENT TO THE BEGINNING OF A SINGLE LINKED LIST...

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);

node*move(node*);

int main(void)
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
        next->link=NULL;

        save=next;

        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your linked list...\n\n");

    display(start);

    start=move(start);
    
    printf("\n\nthis is your linked list after moving the smallest element to the first....\n\n");

    display(start);


    save=start;
    node*prv=save;

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

    printf("X\n");
}

node*move(node*s)
{
    node*i=NULL, *smal=s;

    i=s;
    int small=i->data;

    while(i!=NULL)
    {
        if(i->data < small)
        {
            smal=i;
            small=i->data;
        }

        i=i->link;
    }

    node*prev=NULL;

    if(smal->link==NULL)
    {
        prev=s;

        while(prev->link!=smal)
        {
            prev=prev->link;
        }
        prev->link=NULL;
        smal->link=s;
        s=smal;
    }

    else if(smal==s)
    {
        return s;
    }

    else
    {
        prev=s;

        while(prev->link!=smal)
        {
            prev=prev->link;
        }
        prev->link=smal->link;
        smal->link=s;
        s=smal;
    }


    return s;
}