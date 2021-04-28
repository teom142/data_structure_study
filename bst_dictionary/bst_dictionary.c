#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "bst_dictionary.h"

void main()
{
	char c, fname[20];
	char w1[100], * w2;
	int wcount;
	printf("************* Command ************\n");
	printf("R: Read data, S: Search data \n");
	printf("P: Print inorder, Q: Quit \n");
	printf("**********************************\n");
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
			wcount = build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", w1);
			w2 = bst_search(w1);
			if (w2) printf(" Meaning: %s \n", w2);
			else printf(" No such word ! \n");
			break;
		case 'P':
			printf("\n");
			bst_show_inorder(root);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

int build_dictionary(char* fname)
{
	char curr_w1[100], curr_w2[100];
	FILE* fp = fopen(fname, "r");
	int ret = 0;

	while (fscanf(fp, "%s %s", curr_w1, curr_w2) != EOF)
	{
		bst_insert(curr_w1, curr_w2);
		ret++;
	}
	fclose(fp);
	return ret;
}

void bst_insert(char* w1, char* w2)
{
	tree_pointer added_tree = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer curr = root;

	strcpy(added_tree->w1, w1);
	strcpy(added_tree->w2, w2);
	added_tree->left = NULL;
	added_tree->right = NULL;
	if (!curr)
	{
		root = added_tree;
		return;
	}
	while (1)
	{
		if (strcmp(curr->w1, w1) < 0)
		{
			if (curr->right)
				curr = curr->right;
			else
			{
				curr->right = added_tree;
				return;
			}
		}
		if (strcmp(curr->w1, w1) > 0)
		{
			if (curr->left)
				curr = curr->left;
			else
			{
				curr->left = added_tree;
				return;
			}
		}
	}
}
char* bst_search(char* w1)
{
	tree_pointer curr = root;

	if (!curr)
		return curr->w2;
	while (1)
	{
		if (strcmp(curr->w1, w1) < 0)
			curr = curr->right;
		if (strcmp(curr->w1, w1) > 0)
			curr = curr->left;
		if (strcmp(curr->w1, w1) == 0)
			return curr->w2;
		if (curr->left == NULL && curr->right == NULL)
			return 0;
	}
	return 0;
}
void bst_show_inorder(tree_pointer ptr)
{
	if (ptr) {
		bst_show_inorder(ptr->left);
		printf(" %s %s\n", ptr->w1, ptr->w2);
		bst_show_inorder(ptr->right);
	}
}