#include<stdio.h>
#include<stdlib.h>

// sorting linked list using bubble sort!!!

struct node
{
	int data;
	struct node *link;
};

typedef struct node node;

node*start, *save, *next;

void insert(node*);

void sort(node*);

void display(node*);

int main(void)
{
	char ans;

	start=NULL;

	save=(node*)malloc(sizeof(node));
	insert(save);

	start=save;
	start->link=NULL;
	printf("\ndo you want to continue?(y/n): ");
	scanf(" %c", &ans);

	while(ans=='y' || ans=='Y')
	{
		next=(node*)malloc(sizeof(node));
		save->link=next;
		insert(next);
		save=next;
		next->link=NULL;
		printf("do you want to continue?(y/n): ");
		scanf(" %c", &ans);
	}

	printf("\n\nthis is your unsorted list....\n\n");

	display(start);

	sort(start);

	printf("\n\nthis is your sorted list......\n\n");

	display(start);
	save=start;

	free(next);
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

void sort(node*s)
{
	node*i, *j, *adv;  // adv -> advanced node(next node's address is stored in this struct pointer for comparison)
	int temp;

	i=s;
	while(i!=NULL)
	{
		j=s;
		while(j->link!=NULL)
		{
			adv=j->link;
			if(j->data > adv->data)
			{
				temp=j->data;
				j->data=adv->data;
				adv->data=temp;
			}

			j=j->link;
		}

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

	printf("NULL\n\n");

}
