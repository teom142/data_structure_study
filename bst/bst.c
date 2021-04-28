#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "bst.h"

void main() {
    char c, grade;
    int id;
    printf("************* Command ************\n");
    printf("I: Insert data, S: Search data \n");
    printf("P: Print inorder, Q: Quit \n");
    printf("**********************************\n");
    while (1) {
        printf("\nCommand> ");
        c = getch();
        putch(c);
        c = toupper(c);
        switch (c) {
        case 'I':
            printf("\n id and grade: ");
            scanf("%d %c", &id, &grade);
            bst_insert(id, grade);
            break;
        case 'S':
            printf("\n id: ");
            scanf("%d", &id);
            grade = bst_search(id);
            if (grade) printf(" Grade of %d: %c \n", id, grade);
            else printf(" No such id ! \n");
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

void bst_insert(int key, char data)
{
    tree_pointer added_tree = (tree_pointer)malloc(sizeof(tree_node));
    tree_pointer curr = root;

    added_tree->data = data;
    added_tree->key = key;
    added_tree->left = NULL;
    added_tree->right = NULL;
    if (!curr)
    {
        root = added_tree;
        return;
    }
    while (1)
    {
        if (curr->key < key)
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = added_tree;
                return;
            }
        }
        if (curr->key > key)
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

char bst_search(int key)
{
    tree_pointer curr = root;

    if (!curr)
        return curr->data;
    while (1)
    {
        if (curr->key < key)
            curr = curr->right;
        if (curr->key > key)
            curr = curr->left;
        if (curr->key == key)
            return curr->data;
    }
}

void bst_show_inorder(tree_pointer ptr)
{
    if (ptr) {
        bst_show_inorder(ptr->left);
        printf(" %d %c\n", ptr->key, ptr->data);
        bst_show_inorder(ptr->right);
    }
}