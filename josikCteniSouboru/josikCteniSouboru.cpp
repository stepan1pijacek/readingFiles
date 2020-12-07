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


char* GetNth(LIST* head, int index)
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
		LIST* node = NULL;
		node = (LIST*) malloc(sizeof(LIST));
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