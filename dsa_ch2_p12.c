#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO PRINT A  LINKED LIST L2 ACCORDING TO LIST L1(which is a sorted list)

/*
if the first linked list is
    1->2->5->7->8->X

then the 1st, 2nd, 5th, 7th and the 8th elements of the second list should be printed
*/


struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*head1,*save,*next,*head2;

void insert(node*);
void display(node*);
void sort(node*);
void disp_l2(node*, node*);

int main(void)
{
    char ans;

    printf("\n\nLINKED LIST - L1:\n\n");

    head1=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    save->link=NULL;
    head1=save;

    printf("\ndo you want to continue?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        insert(next);
        next->link=NULL;
        save->link=next;
        save=next;

        printf("\n\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your sorted linked list....\n\n");

    sort(head1);
    display(head1);

    printf("\n\nLINKED LIST - L2:\n\n");

    head2=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    save->link=NULL;
    head2=save;

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

    printf("\nthis is your linked list...\n\n");
    display(head2);


    printf("\n\ndisplaying L2 with respect to L1....\n\n");

    disp_l2(head1, head2);

    save=head1;

    node*prv=save;

    while(save!=NULL)
    {
        save=save->link;
        free(prv);
        prv=save;
    }

    save=head2;

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
    printf("X\n");
}

void sort(node*s)
{
    int temp;

    node*i=s, *j=NULL;

    while(i!=NULL)
    {
        j=s;

        while(j->link!=NULL)
        {
            if(j->data > j->link->data)
            {
                temp=j->data;
                j->data=j->link->data;
                j->link->data=temp;
            }

            j=j->link;
        }

        i=i->link;
    }
}

void disp_l2(node*s1, node*s2)
{
    int count=0;

    node*t=NULL;

    while(s1!=NULL)
    {
        t=s2;

        while(t!=NULL)
        {
            count++;
            if(count==s1->data)
            {
                printf("%d, ", t->data);
                break;
            }

            t=t->link;

        }

        count=0;

        s1=s1->link;
    }

    printf("\n\n");
}
