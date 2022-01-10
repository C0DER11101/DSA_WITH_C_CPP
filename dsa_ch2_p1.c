#include<stdio.h>
#include<stdlib.h>

// PROGRAM TO COUNT THE NUMBER OF OCCURENCES OF AN ELEMENT IN A LINKED LIST......

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void display(node*);
int occurances(node*, int);

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

    printf("\n\nthis is your linked list.....\n\n");

    display(start);

    int value, occr;

    printf("enter the value to count its number of occurances: ");
    scanf("%d", &value);

    occr=occurances(start, value);
    
    if(occr==-1)
    {
        printf("\n\n%d does not exist in the linked list.....\n\n", value);
    }

    else
    {
        printf("\n\n%d occured %d times in the list....\n\n", value, occr);
    }

    save=start;

    free(save);

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

int occurances(node*s, int value)
{
    int count=0;
    while(s!=NULL)
    {
        if(value==s->data)
        {
            count++;
        }

        s=s->link;
    }

    if(count==0)
        return -1;

    else
        return count;
}