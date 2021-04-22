#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"

void main()
{
	char			c, e;
	list_pointer	head, p;

	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;

	printf("************ Command *********** \n");
	printf("+<c>: Insert c, -<c>: Delete c   \n");
	printf("?<c>: Search c, S: Show, Q: Quit \n");
	printf("******************************** \n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case '+':
			e = getch();
			putch(e);
			list_insert(head, e);
			break;
		case '-':
			e = getch();
			putch(e);
			list_delete(head, e);
			break;
		case '?':
			e = getch();
			putch(e);
			p = list_search(head, e);
			if (p) {
				printf("\n %c is in the list. \n", e);
				printf(" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
			}
			else printf("\n %c is not in tne list \n", e);
			break;
		case 'S':
			list_show(head);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;

		}
	}
}

void list_insert(list_pointer head, Element e)
{
	list_pointer new_node = (list_pointer)malloc(sizeof(list_node));

	new_node->link = head->link;
	new_node->data = e;
	head->link = new_node;
}

void list_delete(list_pointer head, Element e)
{
	list_pointer curr = head;
	list_pointer next = curr->link;

	if (list_empty(head))
	{
		printf("\nList is empty\n");
		return;
	}
	while (next)
	{
		if (next->data == e)
		{
			curr->link = next->link;
			free(next);
			return;
		}
		curr = curr->link;
		next = curr->link;
	}
	printf("\n %c is not in the list \n", e);
}

list_pointer list_search(list_pointer head, Element e)
{
	list_pointer curr = head->link;

	while (curr)
	{
		if (curr->data == e)
			return curr;
		curr = curr->link;
	}
	return 0;
}

bool list_empty(list_pointer head)
{
	if (!head->link)
		return true;
	return false;
}

void list_show(list_pointer head)
{
	list_pointer curr = head->link;

	printf("\n");
	if (list_empty(head))
	{
		printf("List is empty\n");
		return;
	}
	while (curr)
	{
		printf("%c ", curr->data);
		curr = curr->link;
	}
}

