#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
	int data, key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;
struct DataItem *item2;

int HashCode(int key) {
	return key % SIZE;
}

struct DataItem *Search(int key) {
	int hashIndex = HashCode(key);

	while (hashArray[hashIndex] != NULL) {
		if (hashArray[hashIndex]->key == key) return hashArray[hashIndex];
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;
}

void Insert(int key, int data) {
	item = (struct DataItem*)malloc(sizeof(struct DataItem));
	item->data = data;
	item->key = key;

	int hashIndex = HashCode(key);

	while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
		++hashIndex;
		hashIndex %= SIZE;
	}
	hashArray[hashIndex] = item;
}

struct DataItem *Delete(int key) {
	struct DataItem *temp;

	int hashIndex = HashCode(key);

	while (hashArray[hashIndex] != NULL) {
		if (hashArray[hashIndex]->key == key) {
			temp = hashArray[hashIndex];
			hashArray[hashIndex] = dummyItem;
			return temp;
		}
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;
}

void Display() {
	int i;

	for (i = 0; i < SIZE; i++) {
		if (hashArray[i] != NULL) printf(" (%d,%d) ", hashArray[i]->key, hashArray[i]->data);
		else printf(" -- ");
	}
	printf("\n");
}

int main() {

	Insert(1, 20);
	Insert(2, 70);
	Insert(42, 80);
	Insert(4, 25);
	Insert(12, 44);
	Insert(14, 32);
	Insert(17, 11);
	Insert(13, 78);
	Insert(37, 97);
	
	Display();

	item2 = Delete(17);
	item = Search(17);

	if (item != NULL) printf("Found: %d\n", item->data);
	else printf("Not Found!\n");

	Display();

	return 0;
}