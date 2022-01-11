#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO CREATE A COPY OF A SINGLE LINKED LIST.....

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start,*save,*next,*start2;

void insert(node*);
void display(node*);
void copy(node*);

int main(void)
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

    printf("\n\nthis is linked list....\n\n");

    display(start);

    copy(start);

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

void copy(node*s)
{
    start2=NULL;
    while(s!=NULL)
    {
        if(start2==NULL)
        {
            save=(node*)malloc(sizeof(node));
            save->data=s->data;
            start2=save;
            start2->link=NULL;
        }

        else
        {
            next=(node*)malloc(sizeof(node));
            next->data=s->data;
            next->link=NULL;
            save->link=next;
            save=next;
        }

        s=s->link;
    }

    printf("\n\nthis is the copy of your linked list.....\n\n");

    display(start2);

    save=start2;
    node*prv;
    prv=save;

    while(save!=NULL)
    {
        save=save->link;
        free(prv);
        prv=save;
    }
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