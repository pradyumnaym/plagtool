#include <stdio.h>
#include <stdlib.h>

typedef struct List_Node
{
	int data;
	struct List_Node *link;
} List_Node;
typedef struct lst
{
	struct List_Node *head;
	int length;
} lst;

int function_to_insert(lst *lister, int positron, int num_dat)
{
	List_Node *temporary_pointer = (List_Node *)malloc(sizeof(List_Node));
	temporary_pointer->data = num_dat;
	List_Node *p_is_a_pointer, *q_is_a_pointer;
	int i = 0;
	if (lister->head != NULL)
	{
		if (positron >= 0)
		{
			p_is_a_pointer = lister->head;
			q_is_a_pointer = NULL;

			while ((p_is_a_pointer != NULL) && (i < positron))
			{
				q_is_a_pointer = p_is_a_pointer;
				p_is_a_pointer = p_is_a_pointer->link;
				i++;
			}
			if (p_is_a_pointer != NULL)
			{
				if (q_is_a_pointer == NULL)
				{

					lister->head = temporary_pointer;
					temporary_pointer->link = p_is_a_pointer;
					return positron;
				}
				else
				{
					q_is_a_pointer->link = temporary_pointer;
					temporary_pointer->link = p_is_a_pointer;
					return positron;
				}
			}
			else
			{
				if (i == (positron))
				{
					q_is_a_pointer->link = temporary_pointer;
					temporary_pointer->link = NULL;
					return positron;
				}
			}
		}
	}
	else
	{
		if (positron == 0)
		{
			lister->head = temporary_pointer;
			temporary_pointer->link = NULL;
			return positron;
		}
		else
		{
			free(temporary_pointer);
			return -1;
		}
	}
}

void function_to_insert_beg(lst *lister, int num_dat)
{
	List_Node *noderator = (List_Node *)malloc(sizeof(List_Node));
	noderator->data = num_dat;
	if (lister->head == NULL)
	{
		lister->head = noderator;
		noderator->link = NULL;
	}
	else
	{
		noderator->link = lister->head;
		lister->head = noderator;
	}
}

void function_to_rev(lst *lister)
{
	struct List_Node *previous_pointer, *present_pointer, *temp_pointer;
	previous_pointer = NULL;
	present_pointer = lister->head;
	if (present_pointer != NULL)
	{
		if (present_pointer->link != NULL)
		{
			while (present_pointer != NULL)
			{
				temp_pointer = present_pointer->link;
				present_pointer->link = previous_pointer;
				previous_pointer = present_pointer;
				present_pointer = temp_pointer;
			}
			lister->head = previous_pointer;
		}
	}
}

void del_end(lst *lster)
{
	List_Node *present_is_a_pointer = lster->head;
	List_Node *pr_pointer = NULL;
	if (present_is_a_pointer != NULL)
	{
		if (present_is_a_pointer->link == NULL)
		{
			free(present_is_a_pointer);
			lster->head = NULL;
		}
		else
		{
			while (present_is_a_pointer->link != NULL)
			{
				pr_pointer = present_is_a_pointer;
				present_is_a_pointer = present_is_a_pointer->link;
			}
			free(pr_pointer->link);
			pr_pointer->link = NULL;
		}
	}
}

void disper(lst *this_is_a_list)
{
	List_Node *this_is_not_a_present_pointer = this_is_a_list->head;
	while (this_is_not_a_present_pointer != NULL)
	{
		printf("%d ", this_is_not_a_present_pointer->data);
		this_is_not_a_present_pointer = this_is_not_a_present_pointer->link;
	}
	printf("\n");
}

int main()
{
	lst *list = (lst *)malloc(sizeof(lst));
	list->head = NULL;
	list->length = 0;

	int option = 1;
	int num = 0;
	int posi = 0;
	while (option)
	{
		disper(list);
		printf("enter\n");
		scanf("%d", &option);
		switch (option)
		{
		case 5:
			scanf("%d", &num);

			function_to_insert_beg(list, num);
			break;
		case 1:
			scanf("%d", &num);
			scanf("%d", &posi);
			function_to_insert(list, posi, num);
			break;

		case 2:
			function_to_rev(list);
			break;
		case 3:
			del_end(list);
			break;
		case 4:
			disper(list);
			break;
		}
	}
}
