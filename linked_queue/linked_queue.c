#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_queue.h"

void main()
{
	char	c, e;

	front = rear = NULL;

	printf("########### Command ###########\n");
	printf("+<c>: AddQ c, -: DeleteQ, \n");
	printf("S: Show, Q: Quit \n");
	printf("###############################\n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		//getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
		case '+':
			e = _getch();
			//getch();
			_putch(e);
			addq(e);
			break;
		case '-':
			if (is_queue_empty()) {
				printf("\n Queue is empty !!! \n");
			}
			else {
				e = deleteq();
				printf("\n %c ", e);
			}
			break;
		case 'S':
			queue_show();
			break;
		case 'Q': printf("\n");
			exit(1);
		default: break;
		}
	}
}

void addq(Element e)
{
	queue_pointer new_queue = (queue_pointer)malloc(sizeof(queue));

	new_queue->item = e;
	new_queue->link = NULL;
	if (is_queue_empty())
		front = rear = new_queue;			//ó������ ť�� ��Ҹ� �߰��ϸ� front�� rear��� ť�� �߰��� ���ο� ��Ҹ� ����Ų��.
	else
	{
		rear->link = new_queue;				//ť�� �̹� ��Ұ� ����־��ٸ� ��Ҹ� �߰��ϰ� rear�� �ش� ��Ҹ� ����Ű�� �� ����
		rear = rear->link;					//rear�� ����Ű�� �ִ� ����� link�ּҸ� �̿��� rear���� �����Ѵ�.
	}
}

Element deleteq()
{
	queue_pointer temp = front;
	Element front_item;

	front = front->link;
	front_item = temp->item;
	free(temp);
	return front_item;
}

void queue_show()
{
	queue_pointer curr = front;

	printf("\n");
	while (curr)
	{
		printf("%c ", curr->item);
		curr = curr->link;
	}
	printf("\n");
}

boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}


