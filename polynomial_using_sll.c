#include<stdio.h>
#include<stdlib.h>

// THIS PROGRAM JUST IMPLEMENTS THE CONCEPT OF CREATING POLYNOMIALS USING LINKED LISTS.....

struct node
{
    float coefficient;
    int exponent;
    struct node *link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void disp_poly(node*); // displays the polynomial


int main(void)
{
    start=NULL;
    save=(node*)malloc(sizeof(node));

    insert(save);

    start=save;
    start->link=NULL;

    char ans;

    printf("\ndo you want to enter more terms?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        insert(next);
        save->link=next;
        next->link=NULL;
        save=next;

        printf("\ndo you want to enter more terms?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\n\nthis is your polynomial......\n\n");

    disp_poly(start);

    save=start;

    free(save);

    return 0;

}


void insert(node*s)
{
    float coef; int expo;

    printf("enter the coefficient: ");
    scanf("%f", &coef);

    printf("enter the exponent: ");
    scanf("%d", &expo);


    s->coefficient=coef;

    s->exponent=expo;

}


void disp_poly(node*s)
{
    while(s!=NULL)
    {
        printf("%.2fx^%d->", s->coefficient, s->exponent);

        s=s->link;
    }

    printf("\n\n\n");
}