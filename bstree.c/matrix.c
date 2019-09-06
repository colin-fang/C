#include "matrix.h"
Matrix matrix_construction(void) {
//Matrix construction using bstree ini();
	Matrix m;
	m = bstree_ini();
	return m;
}
unsigned char matrix_isin(Matrix m, Index index1, Index index2) {
//If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
	//generate a key using the indices
	Key mkey = key_gen(index1, index2);
	//use the bstree_search to determine if the node with key mkey is in the tree
	if (bstree_search(m, mkey) != NULL) {
		return '1'; //if found
	} else {
		return '0'; //if not found
	}
}
Value *matrix_get(Matrix m, Index index1, Index index2) {
//If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
//value. Otherwise, return NULL.
	//check if the node is in the tree
	if (matrix_isin(m, index1, index2) == '1') {
		//generate key using the inidices
		Key mkey = key_gen(index1, index2);
		//use bstree_search to return the data
		Data d = bstree_search(m, mkey);
		return d;
		//if the node is not in the tree, return NULL
	} else {
		return NULL;
	}
}
void matrix_set(Matrix m, Index index1, Index index2, Value value) {
//Assign value to Matrix m at location (index1, index2). If that location already has value,
//then overwrite.
	//check if the node is in the tree
	if (matrix_isin(m, index1, index2) == '0') {
		//if the node is not in the tree, insert the node
		bs_tree_insert(m, key_gen(index1, index2), data_gen(value));
	} else {
		//if the node is in the tree, set the target value to the new value
		Value *target;
		target = matrix_get(m, index1, index2);
		*target = value;
	}

}
void matrix_inc(Matrix m, Index index1, Index index2, Value value) {
//If location (index1, index2) is defined in Matrix m, then increase the associated value by
//value. Otherwise, report error.
//3
	//generate a key using the indices
	Key mkey = key_gen(index1, index2);
	//check if the node is in the tree
	if (matrix_isin(m, index1, index2) == '1') {
		//if the node is in the tree, return the data of the node using matrix_get
		Value *mdata = matrix_get(m, index1, index2);
		//increase the data value by the parameter value
		*mdata += value;
	//if the node is not in the tree, report error
	} else {
		printf("Error, key not found \n");
	}
}
void matrix_list(Matrix m) {
//Print indices and values in the Matrix m (with bstree traversal()).
	bstree_traversal(m);
}
void matrix_destruction(Matrix m) {
//Free allocated space (with bstree free()).
	bstree_free(m);
}
