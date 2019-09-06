#include "datatype.h"
char * string_dup(char *str) {
	//dup is the duplicated string
	char *dup;
	//allocate memory
	dup = (char*) malloc(sizeof(char));
	//duplicate string
	dup = strdup(str);
	return dup;
}

Key key_gen(char *skey1, char *skey2) {
	//allocate memory
	Key newKey = (Key) malloc(sizeof(Key));
	//set the skeys to the duplicated parameters
	newKey->skey1 = string_dup(skey1);
	newKey->skey2 = string_dup(skey2);
	return newKey;
}

int key_comp(Key key1, Key key2) {
	//Use strcmp( ) to do comparison.
	int compare, compare2;
	compare = strcmp(key1->skey1, key2->skey1);
	compare2 = strcmp(key1->skey2, key2->skey2);

	//If the key values are the same, compare id
	if (compare == 0) {
		if (compare2 > 0) {
			return 1;
		} else if (compare2 < 0) {
			return -1;
		} else {
			return 0;
		}
	} else {
		return compare; //If the key values are different, return the difference
	}
}

void key_print(Key key) {
//Print a key.
	printf("%s\t\t%s\t\t", key->skey1, key->skey2);
}

void key_free(Key key) {
//Free memory allocated for key.
	free(key->skey1);
	free(key->skey2);
	free(key);
}

Data data_gen(int idata) {
//Generate a data with dynamic memory allocation.
	Data newData = malloc(sizeof(Data));
	*newData = idata;
	return newData;
}

void data_set(Data data, int idata) {
//Assign data with idata.
	*data = idata;
}

void data_print(Data data) {
//Print a data.
	printf("%i \n", *data);
}

void data_free(Data data) {
//Free memory allocated for data.
	free(data);
}
