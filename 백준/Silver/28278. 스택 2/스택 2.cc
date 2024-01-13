#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
	int data;
	struct StackNode* link;
}StackNode;

int size = 0;

StackNode* create_node() {
	StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));
	newnode->data = NULL;
	newnode->link = NULL;
	return newnode;
}

int is_empty(StackNode* top) {
	if (top->data == NULL) return 1;
	else return 0;
}

StackNode* push(StackNode* top, int data) {
	if (top->data == NULL) top->data = data;
	else {
		StackNode* newnode = create_node();
		newnode->data = data;
		newnode->link = top;
		top = newnode;
	}
	size++;
	return top;
}

int pop(StackNode** top) {
	if ((*top)->data == NULL) return -1;
	StackNode* tmp = *top;
	int data = (*top)->data;
	if ((*top)->link == NULL)
		(*top)->data = NULL;
	else {
		*top = (*top)->link;
		free(tmp);
	}
	size--;
	return data;
}

int main() {
	StackNode* top = create_node();
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int menu;
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			int data;
			scanf("%d", &data);
			top = push(top, data);
            break;
		case 2:
			printf("%d\n", pop(&top));
            break;
		case 3:
			printf("%d\n", size);
            break;
		case 4:
			printf("%d\n", is_empty(top));
            break;
		case 5:
			if (top->data == NULL) printf("-1\n");
			else printf("%d\n", top->data);
            break;
		}
	}
}