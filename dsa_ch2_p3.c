#include<stdio.h>
#include<stdlib.h>


// PROGRAM TO CHECK IF TWO LINKED LISTS ARE IDENTICAL OR NOT...

/*
TWO LINKED LISTS ARE IDENTICAL IF THEY HAVE THE SAME NUMBER OF ELEMENTS AND THE CORRESPONDING ELEMENTS IN BOTH THE LISTS ARE THE 
SAME*/

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node *start1, *start2, *save, *next;

void insert(node*);
void display(node*);
int check_identical(node*, node*); // check if two linked lists are identical or not

int main(void)
{
    // LINKED LIST-1
    printf("\n\nLINKED LIST-1:\n\n");
    start1=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    start1=save;
    save->link=NULL;
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

    // LINKED LIST-2
    printf("\n\nLINKED LIST-2:\n\n");
    start2=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);

    save->link=NULL;
    start2=save;

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

    printf("\n\nthese are your linked lists....\n\n");

    display(start1);
    display(start2);

    int areIdentical;

    areIdentical=check_identical(start1, start2);

    if(areIdentical==-1)
    {
        printf("\nthe lists are not identical.....\n\n");
    }

    else
    {
        printf("\nthe lists are identical.....\n\n");
    }

    save=start1;
    node*prv;
    prv=save;
    while(save!=NULL)
    {
        save=save->link;
        free(prv);
        prv=save;
    }

    save=start2;
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

int check_identical(node*s1, node*s2)
{
    int count1=0, count2=0;
    node*i=NULL, *j=NULL;


    // counting the number of elements in both the lists

    i=s1;

    while(i!=NULL)
    {
        count1++;
        i=i->link;
    }

    j=s2;

    while(j!=NULL)
    {
        count2++;
        j=j->link;
    }

    if(count1==count2)
    {
        i=s1;
        j=s2;

        while(i!=NULL && j!=NULL)
        {
            if(i->data != j->data)
            {
                return -1;
            }

            i=i->link;
            j=j->link;
        }

        return 0;
    }

    else
    {
        return -1;
    }
}