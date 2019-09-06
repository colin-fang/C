#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
BStree bstree_ini(void) {
//Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the
//allocated memory.
	BStree newTree = (BStree) malloc(sizeof(BStree_node*));
	(*newTree) = NULL;
	return newTree;
}
BStree_node *create_new_node(Key key, Data data) {
	//generate empty node and assign the key and data values to the parameter values
	//assign NULL to the left and right children, return the node
	BStree_node *newNode;
	newNode = (BStree_node*) malloc(sizeof(BStree_node*));
	(newNode)->key = key;
	(newNode)->data = data;
	(newNode)->left = NULL;
	(newNode)->right = NULL;
	return newNode;
}
//THIS IS THE HELPER FUNCTION
void bst_insert(BStree_node *node_ptr, Key key, Data data) {
	//if target node is to the left of the current node
	if (key_comp(key, node_ptr->key) < 0)
		//check if the left child is empty
		if (node_ptr->left == NULL) {
			//if left child is empty, put target node in
			//use create_new_node to initalize a new node with key and data
			(node_ptr->left) = create_new_node(key, data);
		} else {
			//if the left child is not empty, let the left child be current node and call bst_insert again
			bst_insert(node_ptr->left, key, data);
		}
	//same thing but for the right side
	else if (key_comp(key, node_ptr->key) > 0)
		if (node_ptr->right == NULL) {
			(node_ptr->right) = create_new_node(key, data);
		} else {
			bst_insert(node_ptr->right, key, data);
		}
	//if the target node already exists in the tree, do nothing
	else
		;
}
//THIS IS THE PARENT FUNCTION
void bs_tree_insert(BStree bst, Key key, Data data) {
	//if the tree is empty, set the root node to the target node
	//initialize the target node with create_new_node
	if ((*bst) == NULL) {
		*bst = create_new_node(key, data);
	} else {
		//if the tree is not empty, recursively call bst_insert
		bst_insert(*bst, key, data);
	}
}

Data bstree_search(BStree bst, Key key) {
//If key is in bst, return key’s associated data. If key is not in bst, return NULL.
	//if the tree is empty, return NULL
	if ((*bst) == NULL) {
		return NULL;
	} else {
		//use node as the current node
		BStree_node *node;
		//point node to the root
		node = (*bst);
		while (1) {
			//iterate through the tree until you find an empty node or the target node
			//if an empty node is found, target key is not in tree, return NULL
			if (node == NULL) {
				return NULL;
			}
			//once the target node is found, return the data of that node
			if (key_comp((node)->key, key) == 0) {
				Data data = (node)->data;
				return data;
				//check if the target node is greater or less than the current node and shift the current node accordingly
			} else if (key_comp((node)->key, key) < 0) {
				(node) = (node)->right;
			} else {
				(node) = (node)->left;
			}
		}
	}
}
//THIS IS THE HELPER FUNCTION
void traverse_inorder(struct BStree_node bst) {
	//iterate down the left side of the tree until the end
	if (bst.left != NULL) {
		//call this function on the left child
		traverse_inorder(*(bst.left));
	}
	//print the middle node after the left node
	key_print(bst.key);
	data_print(bst.data);
	//iterate down the right side of the tree until the end
	if (bst.right != NULL) {
		traverse_inorder(*(bst.right));
	}
}
//THIS IS THE PARENT FUNCTION
void bstree_traversal(BStree bst) {
//In order traversal of bst and print each node’s key and data.
	//if the tree is not empty
	if (*bst != NULL) {
		//let the current node, node point to the root
		BStree_node *node;
		node = (*bst);
		//call the helper function
		traverse_inorder(**bst);
		//if the tree is empty, print and do nothing
	} else {
		printf("the tree is empty \n");
	}
}
//THIS IS THE HELPER FUNCTION
static void btree_free(BStree_node *bt) {
	//iterate through the tree and free the key and data of each node
	//when the iteration reaches a leaf node, return
	if (bt != NULL) {
		return;
	}
	//check if the left child is not null
	if (bt->left != NULL) {
		//call the free function on the left child
		btree_free(bt->left);
	}
	//same thing but for the right child
	if (bt->right != NULL) {
		btree_free(bt->right);
	}
	//free the key and data
	key_free(bt->key);
	data_free(bt->data);
}
//THIS IS THE PARENT FUNCTION
void bstree_free(BStree bst) {
//Free all the dynamically allocated memory of bst.
	//iterate through the tree, freeing all the key and data memory starting from the root
	btree_free(*bst);
	//free the tree;
	free(bst);
	bst = NULL;

}
