#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO REVERSE A LINKED LIST KEEPING THE ORIGINAL LIST UNCHANGED!!!

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start,*save,*next,*start2;


void insert(node*);
void display(node*);
void copy(node*); // to create a copy of the original list
void rev_list(node*); // reverse the list keeping the original list unchanged

int main(void)
{
    start=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);

    start=save;
    save->link=NULL;

    char ans;

    printf("\ndo you want to enter more?(y/n): ");
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

void display(node*s)
{
    while(s!=NULL)
    {
        printf("%d->", s->data);
        s=s->link;
    }

    printf("NULL\n\n");
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
            save->link=NULL;
            start2=save;
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

    rev_list(start2);

}

void rev_list(node*s)
{
    node*i=NULL;

    node*fdw,*adv;

    i=s;
    adv=i->link;
    fdw=adv->link;

    while(1)
    {
        adv->link=i;
        i=adv;
        adv=fdw;
        if(fdw==NULL)
        {
            break;
        }
        fdw=fdw->link;
    }

    s->link=NULL;
    s=i;
    
    printf("\n\nthis is the reversed list of the original list...\n\n");

    display(s);

    node*prv;
    save=s;
    prv=save;
    while(save!=NULL)
    {
        save=save->link;
        free(prv);
        prv=save;
    }
}