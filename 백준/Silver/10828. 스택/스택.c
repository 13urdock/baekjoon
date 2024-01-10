#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
	int data;
	struct StackNode* link;
}StackNode;

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
	return data;
}

int size(StackNode* top) {
	if (top->data == NULL) return 0;
	StackNode* p = top;
	int count = 0;
	while (p != NULL) {
		p = p->link;
		count++;
	}
	return count;
}

int main() {
	StackNode* top = create_node();
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char menu[6];
		scanf("%s", menu);

		if (!strcmp("push", menu)) {
			int data;
			scanf("%d", &data);
			top = push(top, data);
		}
		else if (!strcmp("pop", menu)) {
			printf("%d\n", pop(&top));
		}
		else if (!strcmp("size", menu)) {
			printf("%d\n", size(top));
		}
		else if (!strcmp("empty", menu)) {
			printf("%d\n", is_empty(top));
		}
		else if (!strcmp("top", menu)) {
			if (top->data == NULL) printf("-1\n");
			else printf("%d\n", top->data);
		}
	}
}