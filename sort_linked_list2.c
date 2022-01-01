#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;

    struct node*link;
};

typedef struct node node;

node *start, *save, *next;

void insert(node*);
void sort(node*);  // selection sort
void display(node*);

int main(void)
{
    // creating the list....

    // step 1: create the list

    char ans;

    start=NULL;

    save=(node*)malloc(sizeof(node));
    insert(save);
    start=save;
    start->link=NULL;
    printf("do you want to continue?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        insert(next);
        save->link=next;
        save=next;
        save->link=NULL;
        printf("\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your unsorted linked list......\n\n");

    display(start);  // step 2: display the unsorted list

    sort(start);  // step 3: sort the list using selection sort

    printf("\n\nthis is your sorted list.....\n\n");

    display(start);  // step 4: show the sorted list


    save=start;

    free(next);  /*
                    important step of all: free up the memory!!
                */
    free(save);

    return 0;
}


void insert(node*s)
{
    int data;

    printf("\nenter the node information: ");
    scanf("%d", &data);

    s->data=data;
}

void sort(node*s)
{
    node*i, *j, *index=s;
    int temp, small;

    i=s;
    
    while(i->link!=NULL)
    {
        j=i->link;
        small=i->data;
        index=i;

        while(j!=NULL)
        {
            if(j->data < small)
            {
                small=j->data;
                index=j;
            }

            j=j->link;
        }

        temp=i->data;
        i->data=index->data;
        index->data=temp;

        i=i->link;
    }
}


void display(node*s)
{
    while(s!=NULL)
    {
        printf("%d->", s->data);
        s=s->link;
    }

    printf("NULL");

    printf("\n\n");
}