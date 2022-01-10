#include<stdio.h>
#include<stdlib.h>


// THIS PROGRAM SORTS THE TERMS OF THE POLYNOMIAL IN DECREASING ORDER OF THEIR POWER

struct node
{
	float coefficient;
	int exponent;

	struct node *link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
void sort(node*);
void disp_poly(node*);

int main(void)
{
	char ans;

	start=NULL;

	save=(node*)malloc(sizeof(node));
	insert(save);
	start=save;
	start->link=NULL;

	printf("\ndo you want to enter more terms?(y/n): ");
	scanf(" %c", &ans);

	while(ans=='y' || ans=='Y')
	{
		next=(node*)malloc(sizeof(node));
		insert(next);
		save->link=next;
		save=next;
		save->link=NULL;

		printf("\ndo you want to enter more terms?(y/n): ");
		scanf(" %c", &ans);
	}

	printf("\n\nthis is your polynomial:\n");
	disp_poly(start);

	sort(start);

	printf("\n\nthis is the corrected form of your polynomial:\n");
	disp_poly(start);

	save=start;

	free(save);

	return 0;
}

void insert(node*s)
{
	float coef;
	int expo;

	printf("\nenter the coefficient of the term: ");
	scanf("%f", &coef);

	printf("\nenter exponent of the term: ");
	scanf("%d", &expo);

	s->coefficient=coef;

	s->exponent=expo;
}

void sort(node*s)
{
	float ctemp; // to store the coefficients temporarily
	int etemp; // to store the exponents temporarily

	node*i=NULL, *j=NULL, *adv=NULL;

	i=s;

	while(i!=NULL)
	{
		j=s;
		while(j->link!=NULL)
		{
			adv=j->link;

			if(j->exponent < adv->exponent)
			{
				ctemp=j->coefficient;
				j->coefficient=adv->coefficient;
				adv->coefficient=ctemp;
				etemp=j->exponent;
				j->exponent=adv->exponent;
				adv->exponent=etemp;
			}

			j=j->link;
		}

		i=i->link;
	}


}


void disp_poly(node*s)
{
	while(s!=NULL)
	{
		printf("%.1fx^%d->", s->coefficient, s->exponent);

		s=s->link;
	}

	printf("NULL\n\n");
}