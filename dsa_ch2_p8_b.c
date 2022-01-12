#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO SWAP THE FIRST AND THE LAST NODE BY REARRANGING NODES

struct node
{
    int data;
    struct node*link;
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

    printf("\nthis is your linked list....\n\n");

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

void move(node*s)
{
    node*i=NULL, *j=NULL;
    i=s;
    while(i->link!=NULL)
    {
        j=i;  // storing the previous node of ith node
        i=i->link;
    }

    node*temp;
    temp=s;
    s=i;
    i=temp;
    s->link=i->link;
    j->link=i;
    i->link=NULL;


    printf("\nthis is your linked list after swapping first and last nodes by rearranging nodes....\n\n");
    display(s);

}