#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

node*start1,*start2,*start3,*save,*next;


void insert(node*);  // function to create linked lists
void merge_list(node*, node*);  // merges the two linked lists into a third linked list
void display_lists(node*);  // displays the two linked lists

int main(void)
{
    // LINKED-LIST1
    printf("\n\nLINKED LIST-1:\n\n");
    printf("\n\nenter the elements into the list in sorted manner:\n\n\n");
    start1=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    start1=save;
    start1->link=NULL;

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

        printf("\n\ndo you want to continue?(y/n): ");
        scanf(" %c", &ans);
    }

    // LINKED-LIST2
    printf("\n\nLINKED LIST-2:\n\n");
    printf("\n\nenter the elements into the list in sorted manner:\n\n\n");
    start2=NULL;
    save=(node*)malloc(sizeof(node));
    insert(save);
    start2=save;
    start2->link=NULL;
    printf("\n\ndo you want to continue?(y/n): ");
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

    printf("\n\nLIST-1:\n");

    display_lists(start1);

    printf("\n\nLIST-2:\n");
    display_lists(start2);

    merge_list(start1,start2);

    save=start1;

    free(start1);
    save=start2;
    free(save);

    return 0;


}


void insert(node*s)
{
    int data;

    printf("\nenter node data: ");
    scanf("%d", &data);

    s->data=data;
}

void display_lists(node*s)
{
    while(s!=NULL)
    {
        printf("%d->", s->data);
        s=s->link;
    }

    printf("NULL\n\n");
}

void merge_list(node*s1,node*s2)
{
    // MERGING CONCEPT IS SAME AS MERGING OF TWO ARRAYS
    
    start3=NULL;
    while(s1!=NULL || s2!=NULL)
    {
        if(s1==NULL)
        {
            while(s2!=NULL)
            {
                next=(node*)malloc(sizeof(node));
                next->data=s2->data;
                save->link=next;
                save=next;
                next->link=NULL;
                s2=s2->link;
            }

            break;
        }

        if(s2==NULL)
        {
            while(s1!=NULL)
            {
                next=(node*)malloc(sizeof(node));
                next->data=s1->data;
                save->link=next;
                save=next;
                next->link=NULL;
                s1=s1->link;
            }

            break;
        }

        if(s1->data < s2->data)
        {
            if(start3==NULL)
            {
                save=(node*)malloc(sizeof(node));
                save->data=s1->data;
                save->link=NULL;
                start3=save;
            }

            else
            {
                next=(node*)malloc(sizeof(node));
                next->data=s1->data;
                save->link=next;
                save=next;
                next->link=NULL;
            }

            s1=s1->link;
        }

        else if(s2->data < s1->data)
        {
            if(start3==NULL)
            {
                save=(node*)malloc(sizeof(node));
                save->data=s2->data;
                save->link=NULL;
                start3=save;
            }

            else
            {
                next=(node*)malloc(sizeof(node));
                next->data=s2->data;
                save->link=next;
                save=next;
                next->link=NULL;
            }

            s2=s2->link;
        }

        else if(s1->data == s2->data)
        {
            if(start3==NULL)
            {
                save=(node*)malloc(sizeof(node));
                save->data=s2->data;
                save->link=NULL;
                start3=save;
            }

            else
            {
                next=(node*)malloc(sizeof(node));
                next->data=s2->data;
                save->link=next;
                save=next;
                next->link=NULL;
            }

            s1=s1->link;
            s2=s2->link;
        }
    }

    printf("\n\nthis is the merged list......\n\n");

    display_lists(start3);

    save=start3;

    free(save);
}