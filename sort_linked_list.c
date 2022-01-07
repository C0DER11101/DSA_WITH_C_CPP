#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};

typedef struct node node;

node*start,*save,*next;

void insert(node*);
node* sort(node*); // sort by exchanging nodes
void display(node*);

int main(void)
{
	// create the list.....
	start=NULL;

	char ans;

	save=(node*)malloc(sizeof(node));

	insert(save);

	start=save;
	start->link=NULL;

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

	printf("\n\nthis is your unsorted list.....\n\n");

	display(start);

	start=sort(start);

	printf("\n\nthis is your sorted list.....\n\n");

	display(start);

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

node*sort(node*s)
{
	node*temp, *i, *j, *address;
	int small, found=0;

	i=s;

	while(i->link!=NULL)
	{
		j=i->link;
		address=i;
		small=i->data;

		while(j!=NULL)
		{
			if(j->data < small)
			{
				small=j->data;
				found=1;
				address=j;
			}

			j=j->link;
		}

		if(found==1)
		{
			found=0;
			

			if(i==s)
			{
				node*prev, *store1, *store2;

				prev=s;

				while(prev->link!=address)
				{
					prev=prev->link;
				}

				temp=i;
				store1=temp->link;
				store2=address->link;
				prev->link=temp;
				address->link=store1;
				temp->link=store2;
				i=address;
				s=i;
			}

			else  // if the node to be replaced is not the first node
			{

				if(i->link!=address)
				{
					node *prev1, *prev2, *store1, *store2;

					prev1=s;
					while(prev1->link!=i)
					{
						prev1=prev1->link;
					}

					prev2=s;
					while(prev2->link!=address)
					{
						prev2=prev2->link;
					}

					temp=i;

					store1=temp->link;
					store2=address->link;
					prev1->link=address;
					address->link=store1;
					prev2->link=temp;
					temp->link=store2;

					i=address;
				}

				else if(i->link==address)  // if the nodes to be swapped are adjacent
				{
					node *prev1, *prev2, *store1, *store2;

					prev1=s;
					while(prev1->link!=i)
					{
						prev1=prev1->link;
					}

					prev2=s;
					while(prev2->link!=address)
					{
						prev2=prev2->link;
					}

					temp=i;

					store1=temp->link;
					store2=address->link;
					prev1->link=address;
					address->link=temp;
					temp->link=store2;

					i=address;

				}

			}
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
