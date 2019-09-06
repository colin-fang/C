#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
typedef struct BStree_node {
	Key key;
	Data data;
	struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;
BStree bstree_ini(void);
BStree_node *create_new_node(Key key, Data data);
void bst_insert(BStree_node *node_ptr, Key key, Data data);
void bs_tree_insert(BStree bst, Key key, Data data);
Data bstree_search(BStree bst, Key key);
void traverse_inorder(BStree_node bst);
void bstree_traversal(BStree bst);
static void btree_free(BStree_node *bt);
void bstree_free(BStree bst);
