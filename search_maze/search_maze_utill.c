#include "search_maze.h"
location current, S = { 1, 0 }, G = { 8, 9 };
int visited_top = 0;
int top = 0;

char maze[10][10] = {
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{ ' ', ' ', '1', '1', '1', ' ', ' ', ' ', ' ', '1'},
	{ '1', ' ', ' ', ' ', '1', ' ', '1', '1', ' ', '1'},
	{ '1', ' ', '1', ' ', '1', ' ', '1', '1', ' ', '1'},
	{ '1', ' ', ' ', ' ', '1', ' ', ' ', ' ', ' ', '1'},
	{ '1', ' ', '1', '1', '1', ' ', '1', '1', ' ', '1'},
	{ '1', ' ', ' ', ' ', '1', ' ', '1', '1', ' ', '1'},
	{ '1', ' ', '1', ' ', '1', ' ', '1', '1', ' ', '1'},
	{ '1', ' ', '1', ' ', ' ', ' ', ' ', '1', ' ', ' '},
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'} };

void search_maze()
{
	current = S;
	location temp;

	stack_insert(current);
	while (!compare_loc(current, G))
	{
		if (stack_empty())
			printf("fail");
		current = stack_pop();
		maze[current.r][current.c] = '.';
		prt_maze();
		visited_insert(current);
		if (stack_empty_visited(current.r - 1, current.c))
		{
			temp.r = current.r - 1;
			temp.c = current.c;
			stack_insert(temp);
		}
		if (stack_empty_visited(current.r, current.c - 1))
		{
			temp.r = current.r;
			temp.c = current.c - 1;
			stack_insert(temp);
		}
		if (stack_empty_visited(current.r, current.c + 1))
		{
			temp.r = current.r;
			temp.c = current.c + 1;
			stack_insert(temp);
		}
		if (stack_empty_visited(current.r + 1, current.c))
		{
			temp.r = current.r + 1;
			temp.c = current.c;
			stack_insert(temp);
		}
	}
}

void prt_maze()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool stack_empty_visited(int r, int c)
{
	location temp;
	temp.r = r;
	temp.c = c;
	if (r < 0 || c < 0 || r > 9 || c > 9)
		return false;
	if (maze[r][c] == '1')
		return false;
	if (is_visited(temp))
		return false;
	return true;
}

void stack_insert(location l)
{
	if (top < MAX_SIZE)
	{
		stack[top] = l;
		top++;
	}
}

void visited_insert(location l)
{
	if (visited_top < MAX_SIZE)
	{
		visited[visited_top] = l;
		visited_top++;
	}
}

bool is_visited(location l)
{
	for (int i = 0; i < 100; i++)
		if (compare_loc(visited[i], l))
			return true;
	return false;
}

location stack_pop()
{
	if (top != 0)
	{
		top--;
		return stack[top];
	}
	return;
}

bool stack_empty()
{
	if (top == 0)
		return true;
	return false;
}

bool compare_loc(location a, location b)
{
	if (a.c == b.c && a.r == b.r)
		return true;
	return false;
}