#include<stdio.h>
#include<stdlib.h>


// PROGRAM TO SWAP ADJACENT ELEMENTS OF THE LIST UBY EXCHANGING NODE DATA

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);
void swap(node*);

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
        save=next;
        next->link=NULL;

        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }
    
    printf("\n\nthis is your linked list...\n\n");

    display(start);

    printf("\n\nthis is your linked list after swapping adjacent elements......\n\n");
    swap(start);

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
        printf("%d->", s->data);
        s=s->link;
    }

    printf("NULL\n\n");
}

void swap(node*s)
{
    int temp;

    node*i=NULL, *adv=NULL;
    i=s;

    while(i!=NULL)
    {
        if(i->link==NULL)  // if the number of nodes in the list is odd!!!
        {
            break;
        }
        adv=i->link;
        temp=i->data;
        i->data=adv->data;
        adv->data=temp;

        i=i->link->link;  // this skips one node: moves to next node of next node of i
        /* example say addresses are as follows:
        0x100->0x104->0x108->0x112->NULL : these are simple addresses that I have taken to explain;
        say address in i is 0x100, so this satement(i=i->link->link) will skip the address 0x104 and store the address 0x108*/
       
    }

    display(s);
}