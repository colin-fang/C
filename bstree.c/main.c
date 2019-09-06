#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
//these character arrays will hold the inputted strings for each loop
char indOne[100], indTwo[100];
int main() {
	Matrix m = matrix_construction(); //construct a bstree
	while (1) {
		printf(
				"Please enter the first index followed by a space \n and then the second index: ");
		//use scanf to input the user input into the two index arrays
		scanf("%s", indOne);
		//the two if statements check for the quit statement to end this loop
		if (strcmp("quit", indOne) == 0) {
			break;
		}
		scanf("%s", indTwo);
		if (strcmp("quit", indTwo) == 0) {
			break;
		}
		//generate a new key for each loop
		Key newKey = key_gen(indOne, indTwo);
		//check i the new key exists in the bstree
		if (matrix_isin(m, indOne, indTwo) == '1') {
			//if the key exists already, increase occurence by 1
			Value v = 1;
			matrix_inc(m, indOne, indTwo, v);
		} else {
			//if the key does not exist, initialize a new node with occurence value of 1
			Value v = 1;
			matrix_set(m, indOne, indTwo, v);
		}
		printf("enter quit to print traversal \n");
	}
	printf("string1\t\tstring2\t\toccurrence\n");
	//print the list using matrix_list
	matrix_list(m);
	//free the memory
	matrix_destruction(m);

}
