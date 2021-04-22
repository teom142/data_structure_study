#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "arraystack.h"

void main() {

	char	c, e;

	printf("*********** Command **********\n");
	printf("+<c>: Push c, -: Pop, \n");
	printf("S: Show, Q: Quit \n");
	printf("******************************\n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
		case '+':
			e = _getch();
			_putch(e);
			push(e);
			break;
		case '-':
			e = pop();
			printf("\n%c", e);
			break;
		case 'S':
			stack_show();
			break;
		case 'Q': printf("\n");
			exit(1);
		default: break;
		}
	}
}

void push(Element e)
{
	if (top < MAX_SIZE - 1)
	{
		stack[++top] = e;
	}
	else
		printf("\n Stack is full !!!");
}

Element pop()
{
	if (top != -1)
	{
		top--;
		return (stack[top + 1]);
	}
	else
		printf("\n Stack is empty !!!");
	return (NULL);
}

void stack_show()
{
	printf("\n");
	for (int i = 0; i <= top; i++)
		printf(" %c", stack[i]);
}

