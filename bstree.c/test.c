#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
int main() {
	//Datatype tests
	Key key1 = key_gen("a", "a");
	Key key2 = key_gen("a", "b");
	Key key3 = key_gen("a", "b");
	Key key4 = key_gen("C", "C");
	Key key5 = key_gen("S", "S");
	Key key6 = key_gen("C", "S.");
	if (key_comp(key1, key2) > 0) {
		printf("key1 > key2 \n");
	} else if (key_comp(key1, key2) < 0) {
		printf("key1 < key2 \n");
	} else {
		printf("==== \n");
	}
	key_print(key1);
	key_print(key2);
	key_print(key3);
	key_print(key4);
	key_print(key5);
	key_print(key6);
	key_free(key1);
	key_free(key2);
	key_free(key3);
	key_free(key4);
	key_free(key5);
	key_free(key6);
	key_print(key1);

	Data data1 = data_gen(1);
	Data data2 = data_gen(2);
	Data data3 = data_gen(3);

	data_print(data1);
	data_set(data1, 11);
	data_print(data1);
	data_print(data2);
	data_print(data3);
	data_free(data1);
	data_free(data2);
	data_free(data3);
	data_print(data1);

	//BStree tests starts here
	BStree newTree = bstree_ini();
	key1 = key_gen("aa", "aa");
	key2 = key_gen("bb", "bb");
	key3 = key_gen("aa", "ab");
	key4 = key_gen("Z", "Z");
	data1 = data_gen(1);
	data2 = data_gen(2);
	data3 = data_gen(3);
	Data data4 = data_gen(-1);
	bs_tree_insert(newTree, key1, data1);
	bs_tree_insert(newTree, key2, data2);
	bs_tree_insert(newTree, key3, data3);
	bs_tree_insert(newTree, key4, data4);
	bs_tree_insert(newTree, key4, data3);

	//Search tests:
	Data search1 = bstree_search(newTree, key1);
	printf("Search:");
	data_print(search1);

	Data search2 = bstree_search(newTree, key2);
	printf("Search:");
	data_print(search2);

	Data search3 = bstree_search(newTree, key3);
	printf("Search:");
	data_print(search3);

	Data search4 = bstree_search(newTree, key4);
	printf("Search:");
	data_print(search4);

	//Traversal tests:
	printf("\n");
	bstree_traversal(newTree);
	bstree_free(newTree);
	bstree_traversal(newTree);

	//matrix tests start here:
	Matrix m = matrix_construction();
	matrix_set(m, "a", "a", 123);
	unsigned char check1 = matrix_isin(m, "a", "a");
	printf("%c \n", check1);
	Value *getV1 = matrix_get(m, "a", "a");
	if (getV1 != NULL) {
		printf("the value of this node is: %d \n", *getV1);
	} else {
		printf("the key cannot be found \n");
	}

	matrix_set(m, "b", "b", 234);
	unsigned char check2 = matrix_isin(m, "b", "b");
	printf("%c \n", check2);
	Value *getV2 = matrix_get(m, "b", "b");
	if (getV2 != NULL) {
		printf("the value of this node is: %d \n", *getV2);
	} else {
		printf("the key cannot be found \n");
	}

	matrix_set(m, "a", "b", 345);
	unsigned char check3 = matrix_isin(m, "a", "b");
	printf("%c \n", check3);
	Value *getV3 = matrix_get(m, "a", "b");
	if (getV3 != NULL) {
		printf("the value of this node is: %d \n", *getV3);
	} else {
		printf("the key cannot be found \n");
	}

	matrix_set(m, "Z", "Z", 456);
	unsigned char check4 = matrix_isin(m, "Z", "Z");
	printf("%c \n", check4);
	Value *getV4 = matrix_get(m, "Z", "Z");
	if (getV4 != NULL) {
		printf("the value of this node is: %d \n", *getV4);
	} else {
		printf("the key cannot be found \n");
	}

	//Check for non-existing node
	unsigned char check0 = matrix_isin(m, "0", "0");
	printf("%c \n", check0);
	Value *getV0 = matrix_get(m, "0", "0");
	if (getV0 != NULL) {
		printf("the value of this node is: %d \n", *getV0);
	} else {
		printf("the key cannot be found \n");
	}

	//overwrite node 1
	matrix_set(m, "a", "a", 1123);
	check1 = matrix_isin(m, "a", "a");
	printf("%c \n", check1);
	getV1 = matrix_get(m, "a", "a");
	if (getV1 != NULL) {
		printf("the value of this node is: %d \n", *getV1);
	} else {
		printf("the key cannot be found \n");
	}
	//try increase
	matrix_inc(m, "a", "a", 100);
	matrix_inc(m, "0", "0", 100);
	//try list
	matrix_list(m);
	matrix_destruction(m);
	printf("tests are done! \n");

	return 0;
}
