#pragma once
#define	bool	unsigned char
#define	true	1
#define	false	0
#define MAX_SIZE 100

#include <stdio.h>

typedef struct {
	int 	r;
	int 	c;
} location;

location stack[MAX_SIZE];
location visited[MAX_SIZE];

typedef struct list_node* list_pointer;
typedef struct list_node {
	location item;
	list_pointer link;
} list_node;

bool stack_empty_visited(int r, int c);
void stack_insert(location l);
void visited_insert(location l);
bool is_visited(location l);
location stack_pop();
bool stack_empty();

void search_maze();
bool compare_loc(location a, location b);
void prt_maze();