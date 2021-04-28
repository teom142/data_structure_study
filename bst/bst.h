#pragma once
// Binary search tree node
typedef struct tree_node* tree_pointer;
typedef struct tree_node {
	int key;
	char data;
	tree_pointer left;
	tree_pointer right;
} tree_node;
tree_pointer root; // BST�� root�� ����Ű�� ������ (��������)
// Ʈ���� (key, data) �ڷ� ����
void bst_insert(int key, char data);
// Ʈ������ Ű���� key�� �ڷḦ �˻�, data�� ��ȯ
char bst_search(int key);
// Ʈ���� �ڷ���� inorder�� ���
void bst_show_inorder(tree_pointer ptr);