#include<stdio.h>
#include<stdlib.h>

struct node
{
    float coefficient;
    int exponent;
    struct node *link;
};

typedef struct node node;

node*start1,*save,*next,*start2,*start3;

void create_poly(node*);
void disp_poly(node*);
void multiply(node*, node*);

int main(void)
{
    // POLYNOMIAL-1
    start1=NULL;
    printf("\nPOLYNOMIAL-1:\n\n");
    save=(node*)malloc(sizeof(node));
    create_poly(save);
    start1=save;
    save->link=NULL;

    char ans;

    printf("\ndo you want to enter more terms?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        create_poly(next);
        save->link=next;
        next->link=NULL;
        save=next;

        printf("\ndo you want to enter more terms?(y/n): ");
        scanf(" %c", &ans);
    }

    // POLYNOMIAL-2

    printf("\nPOLYNOMIAL-2:\n\n");
    start2=NULL;

    save=(node*)malloc(sizeof(node));
    create_poly(save);
    start2=save;
    start2->link=NULL;

    printf("\ndo you want to enter more terms?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(node*)malloc(sizeof(node));
        create_poly(next);
        save->link=next;
        next->link=NULL;
        save=next;

        printf("\ndo you want to enter more terms?(y/n): ");
        scanf(" %c", &ans);
    }

    printf("\nPOLYNOMIAL-1:\n\n");
    disp_poly(start1);
    printf("\nPOLYNOMIAL-2:\n\n");
    disp_poly(start2);

    printf("\n\nthe resultant polynomial after multiplying the two polynomials......\n\n");

    multiply(start1, start2);

    save=start1;

    free(save);

    save=start2;
    free(save);

    return 0;
}

void create_poly(node*s)
{
    float coef;
    int expo;

    printf("enter the coefficient of the term: ");
    scanf("%f", &coef);
    printf("enter exponent of the term: ");
    scanf("%d", &expo);

    s->coefficient=coef;
    s->exponent=expo;
}

void multiply(node*s1,node*s2)
{
    start3=NULL;
    node*i=NULL, *j=NULL;

    i=s1;

    while(i!=NULL)
    {
        j=s2;
        while(j!=NULL)
        {
            if(start3==NULL)
            {
                save=(node*)malloc(sizeof(node));
                save->coefficient=i->coefficient * j->coefficient;
                save->exponent=i->exponent + j->exponent;
                save->link=NULL;
                start3=save;
            }

            else
            {
                next=(node*)malloc(sizeof(node));
                next->coefficient=i->coefficient * j->coefficient;
                next->exponent=i->exponent + j->exponent;
                next->link=NULL;
                save->link=next;
                save=next;
            }

            j=j->link;
        }

        i=i->link;
    }

    disp_poly(start3);

    save=start3;
    free(save);
}

void disp_poly(node*s)
{
    while(s!=NULL)
    {
        printf("%.1fx^%d -> ", s->coefficient, s->exponent);
        s=s->link;
    }

    printf("NULL\n\n");
}