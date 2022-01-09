#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};

typedef struct node node;

node*start, *save, *next;

void insert(node*);
node*sort(node*); // bubble sort
void display(node*);

int main(void)
{
    char ans;
    
    start=NULL;
    
    save=(node*)malloc(sizeof(node));
    
    insert(save);
    
    start=save;
    save->link=NULL;
    
    printf("\n\ndo you want to continue?(y/n): ");
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
    
    printf("\n\nthis is your unsorted linked list....\n\n");
    
    display(start);
    
    start=sort(start);
    
    printf("\nthis is your sorted list....\n\n");
    
    display(start);
    
    save=start;
    
    free(save);
    
    return 0;
}

void insert(node*s)
{
    int data;
    printf("\n\nenter node data: ");
    scanf("%d", &data);
    
    s->data=data;
    
}

node*sort(node*s)
{
    node*i=NULL, *j=NULL, *temp=NULL, *adv=NULL;
    
    i=s;
    
    while(i!=NULL)
    {
        j=s;
        while(j->link!=NULL)
        {
            adv=j->link;
            
            if(j->data > adv->data)
            {
                if(j==s) // if j is the first node then the swapping is simple
                {
                    temp=j;
                    j=adv;
                    adv=temp;
                    adv->link=j->link;
                    j->link=adv;
                    s=j;
                    i=j;
                }
                
                else
                {
                    node*prev, *store;
                    prev=s;
                    while(prev->link!=j)
                    {
                        prev=prev->link;
                    }
                    
                    store=adv->link;
                    
                    temp=j;
                    j=adv;
                    adv=temp;
                    
                    j->link=adv;
                    prev->link=j;
                    adv->link=store;
                }
            }
            
            j=j->link;
        }
        
        i=i->link;
    }
    
    return s;
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
