// josikCteniSouboru.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>


using namespace std;

struct list {
	char* string;
	struct list* next;
};

typedef struct list LIST;
/*typedef struct node {
	char* val;
	struct node* next;
} node_t;

#define CHUNK 1024
char* ReadFile(const char* filename) {
	char buffer[CHUNK];
	char line[128];
	node_t* x, * head = NULL;
	FILE* file;
	size_t nread;
	FILE* stream;

	errno_t err = fopen_s(&file, filename, "r");

	while (fgets(line, sizeof(line), file)) {
		head = (node_t*) malloc(sizeof(node_t));
		head->val = _strdup(line);
		head->next = NULL;

		if (head == NULL) {
			current = x = head;
		}
		else
		{
			current = current->next;
		}
	}

	fclose(file);

	return buffer;
}

void writeList(node_t* head) {
	node_t* current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

int main(void)
{
	char* stream = ReadFile("test.txt");
	char line[128];
	int rngQuestion = rand() % 4;

	node_t *head, *current = NULL;
	head = (node_t*) malloc(sizeof(node_t));
	
	if (head == NULL) {
		return 1;
	}

	return 0;
}*/

char GetNth(LIST* head, int index)
{
	LIST* current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index)
			return (current->string);
		count++;
		current = current->next;
	}
	assert(0);
}

int main(void) {
	FILE* fp;
	char line[128];
	LIST* current, * head;
	int rngQuestion = rand() % 10;
	head = current = NULL;
	errno_t err = fopen_s(&fp,"test.txt", "r");

	while (fgets(line, sizeof(line), fp)) {
		LIST* node = (LIST*) malloc(sizeof(LIST));
		node->string = _strdup(line);//note : strdup is not standard function
		node->next = NULL;

		if (head == NULL) {
			current = head = node;
		}
		else {
			current = current->next = node;
		}
	}
	fclose(fp);
	//test print
    printf_s("Otazka: %d", GetNth(head, rngQuestion));

	//need free for each node
	return 0;
}