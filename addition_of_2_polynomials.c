#include<stdio.h>
#include<stdlib.h>

struct node
{
	float coefficient;
	int exponent;

	struct node *link;
};

typedef struct node node;

node*start1,*save,*next,*start2, *start3;

void create_poly(node*);
void add_poly(node*, node*);
void disp_poly(node*);

void main(void)
{
	char ans;

	// POLYNOMIAL-1

	printf("\n\nPOLYNOMIAL-1:\n\n");
	start1=NULL;
	save=(node*)malloc(sizeof(node));
	create_poly(save);
	start1=save;
	save->link=NULL;
	printf("\ndo you want to enter more terms?(y/n): ");
	scanf(" %c", &ans);

	while(ans=='y' || ans=='Y')
	{
		next=(node*)malloc(sizeof(node));
		create_poly(next);
		save->link=next;
		save=next;
		next->link=NULL;

		printf("\ndo you want to enter more terms?(y/n): ");
		scanf(" %c", &ans);
	}

	// POLYNOMIAL-2

	printf("\n\nPOLYNOMIAL-2:\n\n");
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
		save=next;
		next->link=NULL;

		printf("\ndo you want to enter more terms?(y/n): ");
		scanf(" %c", &ans);
	}

	printf("\n\nPOLYNOMIAL-1:\n\n");
	disp_poly(start1);

	printf("\n\nPOLYNOMIAL-2:\n\n");
	disp_poly(start2);

	printf("\n\nthe resultant polynomial after adding the two polynomials is:\n\n");
	add_poly(start1, start2);

	save=start1;
	free(save);

	save=start2;
	free(save);
}

void create_poly(node*s)
{
	float coef;
	int expo;

	printf("enter coefficient of the term: ");
	scanf("%f", &coef);

	printf("enter exponent: ");
	scanf("%d", &expo);

	s->coefficient=coef;
	s->exponent=expo;
}

void add_poly(node*s1, node*s2)
{
	start3=NULL;

	while(s1!=NULL || s2!=NULL)
	{

		if(s1==NULL)
		{
			while(s2!=NULL)
			{
				next=(node*)malloc(sizeof(node));
				save->link=next;
				next->coefficient=s2->coefficient;
				next->exponent=s2->exponent;
				save=next;
				next->link=NULL;
				s2=s2->link;
			}
			break;
		}

		else if(s2==NULL)
		{
			while(s1!=NULL)
			{
				next=(node*)malloc(sizeof(node));
				save->link=next;
				next->coefficient=s1->coefficient;
				next->exponent=s1->exponent;
				save=next;
				next->link=NULL;
				s1=s1->link;
			}
			break;
		}

		if(s1->exponent > s2->exponent)
		{
			if(start3==NULL)
			{
				save=(node*)malloc(sizeof(node));
				save->coefficient=s1->coefficient;
				save->exponent=s1->exponent;
				start3=save;
				start3->link=NULL;
			}

			else
			{
				next=(node*)malloc(sizeof(node));
				save->link=next;

				next->coefficient=s1->coefficient;
				next->exponent=s1->exponent;
				save=next;
				next->link=NULL;
			}

			s1=s1->link;
		}

		else if(s2->exponent > s1->exponent)
		{
			if(start3==NULL)
			{
				save=(node*)malloc(sizeof(node));
				save->coefficient=s2->coefficient;
				save->exponent=s2->exponent;
				start3=save;
				start3->link=NULL;
			}

			else
			{
				next=(node*)malloc(sizeof(node));
				save->link=next;

				next->coefficient=s2->coefficient;
				next->exponent=s2->exponent;
				save=next;
				next->link=NULL;
			}

			s2=s2->link;
		}

		else if(s1->exponent == s2->exponent)
		{
			if(start3==NULL)
			{
				save=(node*)malloc(sizeof(node));
				save->coefficient=s1->coefficient + s2->coefficient;
				save->exponent=s2->exponent;
				start3=save;
				start3->link=NULL;
			}

			else
			{
				next=(node*)malloc(sizeof(node));
				save->link=next;

				next->coefficient=s1->coefficient + s2->coefficient;
				next->exponent=s2->exponent;
				save=next;
				next->link=NULL;
			}

			s1=s1->link;
			s2=s2->link;
		}
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