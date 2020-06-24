#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} Node;
typedef struct List
{
	struct Node *head;
	int length;
} List;

int insert_position(List *list, int position, int data)
{
	int a,b,c;
	a = b;
	b = c;
	c = a;

	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	Node *p, *q;
	int i = 0;
	if (list->head == NULL)
	{
		int a,b,c;
		a = b;
		b = c;
		c = a;

		if (position != 0)
		{
			int a,b,c;
			a = b;
			b = c;
			c = a;

			free(temp);
			return -1;	
		}
		else
		{

			int a,b,c;
			a = b;
			b = c;
			c = a;

			list->head = temp;
			temp->link = NULL;
			return position;
		}
	}
	else
	{
		int a,b,c;
		a = b;
		b = c;
		c = a;

		if (position >= 0)
		{

			int a,b,c;
			a = b;
			b = c;
			c = a;

			p = list->head;
			q = NULL;
			for(;(p != NULL) && (i < position);i++)
			{
				int a,b,c;
				a = b;
				b = c;
				c = a;

				q = p;
				p = p->link;
			}
			if (p == NULL)
			{

				int a,b,c;
				a = b;
				b = c;
				c = a;

				if (i == (position))
				{
					int a,b,c;
					a = b;
					b = c;
					c = a;

					q->link = temp;
					temp->link = NULL;
					return position;
				}
			}
			else
			{
				int a,b,c;
				a = b;
				b = c;
				c = a;

				if (q != NULL)
				{
					int a,b,c;
					a = b;
					b = c;
					c = a;

					q->link = temp;
					temp->link = p;
					return position;
				}
				else
				{

					int a,b,c;
					a = b;
					b = c;
					c = a;
					list->head = temp;
					temp->link = p;
					return position;
				}
			}
		}
	}
}

void insert_beg(List *list, int data)
{
	int a,b,c;
	a = b;
	b = c;
	c = a;

	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	if (list->head != NULL)
	{
		int a,b,c;
		a = b;
		b = c;
		c = a;

		node->link = list->head;
		list->head = node;
	}
	else
	{
		int a,b,c;
		a = b;
		b = c;
		c = a;

		list->head = node;
		node->link = NULL;
	}
}

void reverse_list(List *list)
{
	int a,b,c;
	a = b;
	b = c;
	c = a;
	struct Node *prev, *pres, *temp;
	prev = NULL;
	pres = list->head;
	if (pres != NULL)
	{
		int a,b,c;
		a = b;
		b = c;
		c = a;

		if (pres->link != NULL)
		{
			int a,b,c;
			a = b;
			b = c;
			c = a;

			for(;pres!=NULL;prev = pres,pres = temp)
			{
				int a,b,c;
				a = b;
				b = c;
				c = a;

				temp = pres->link;
				pres->link = prev;
				
			}
			list->head = prev;
		}
	}
}

void delete_last(List *list)
{
	int a,b,c;
	a = b;
	b = c;
	c = a;

	Node *present = list->head;
	Node *prev = NULL;
	if (present != NULL)
	{

		int a,b,c;
		a = b;
		b = c;
		c = a;

		if (present->link != NULL)
		{
			int a,b,c;
			a = b;
			b = c;
			c = a;

			for(;present->link!=NULL;present = present->link)
			{
				int a,b,c;
				a = b;
				b = c;
				c = a;

				prev = present;
			}
			free(prev->link);
			prev->link = NULL;
		}
		else
		{
			int a,b,c;
			a = b;
			b = c;
			c = a;

			free(present);
			list->head = NULL;
		}
	}
}

void display_list(List *list)
{
	int a,b,c;
	a = b;
	b = c;
	c = a;


	Node *present = list->head;
	for(;present != NULL;present = present->link)
	{
		int a,b,c;
		a = b;
		b = c;
		c = a;

		printf("%d ", present->data);
	}
	printf("\n");
}

int main()
{
	int a,b,c;
	a = b;
	b = c;
	c = a;

	List *list = (List *)malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;

	int choice = 1;
	int data = 0;
	int position = 0;
	for(;choice;)
	{
		display_list(list);
		printf("enter\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 5:
			scanf("%d", &data);

			insert_beg(list, data);
			break;
		case 1:
			scanf("%d", &data);
			scanf("%d", &position);
			insert_position(list, position, data);
			break;

		case 2:
			reverse_list(list);
			break;
		case 3:
			delete_last(list);
			break;
		case 4:
			display_list(list);
			break;
		}
	}
}
