#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO DELETE ALL THOSE NODES WHICH HAVE THE VALUE N

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);
node*delete(node*, int);

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
        next->link=NULL;
        save->link=next;
        save=next;

        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\nthis is your linked list.....\n\n");

    display(start);

    int val;

    printf("\nenter the value to be deleted from the linked list.....\n\n");
    scanf("%d", &val);

    start=delete(start, val);

    printf("\n\nthis is your linked list after deleting all the nodes containing %d \n\n", val);

    display(start);

    save=start;

    node*prv=save;

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
        printf("%d->",s->data);
        s=s->link;
    }

    printf("X\n");
}

node* delete(node*s, int val)
{
    node*i=s, *j=NULL;
    
    while(i!=NULL)
    {
        if(i->data==val && i==s)
        {
            node*temp=NULL;
            temp=i;
            i=i->link;
            free(temp);
            s=i;
            continue;
        }

        else if(i->data==val && i->link==NULL)
        {
            j->link=NULL;
            free(i);
            i=j;
        }

        else if(i->data==val)
        {
            node*temp=NULL;
            temp=i;
            j->link=i->link;
            free(i);
            i=j->link;
            continue;

        }

        j=i;
        i=i->link;
    }

    return s;
}