#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct QueueType {
	struct QueueNode* front;
	struct QueueNode* rear;
}QueueType;

QueueNode* create_node() {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = NULL;
	node->link = NULL;
	return node;
}

QueueType* create_type(QueueNode* node) {
	QueueType* type = (QueueType*)malloc(sizeof(QueueType));
	type->front = node;
	type->rear = node;
	return type;
}

int is_empty(QueueType* queue) {
	if (queue->front == queue->rear && queue->front->data == NULL)
		return 1;
	else return 0;
}

void push(QueueType* queue, int data) {
	if (is_empty(queue)) {
		queue->front->data = data;
		return;
	}
	QueueNode* newnode = create_node();
	newnode->data = data;
	queue->rear->link = newnode;
	queue->rear = newnode;
}

int pop(QueueType* queue) {
	if (is_empty(queue)) return -1;
	if (queue->front == queue->rear) {
		int data = queue->front->data;
		queue->front->data = NULL;
		return data;
	}
	QueueNode* q = queue->front;
	int data = q->data;
	queue->front = queue->front->link;
	free(q);

	return data;
}
int size(QueueType* queue) {
	if (is_empty(queue)) return 0;
	int s = 0;
	QueueNode* q = queue->front;
	while (q != NULL) {
		q = q->link;
		s++;
	}
	return s;
}

int main() {
	QueueNode* node = create_node();
	QueueType* queue = create_type(node);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		char menu[6];
		scanf("%s", menu);
		if (!strcmp("push", menu)) {
			int data;
			scanf("%d", &data);
			push(queue, data);
		}
		else if (!strcmp("pop", menu)) {
			printf("%d\n", pop(queue));
		}
		else if (!strcmp("size", menu)) {
			printf("%d\n", size(queue));
		}
		else if (!strcmp("empty", menu)) {
			printf("%d\n", is_empty(queue));
		}
		else if (!strcmp("front", menu)) {
			if (is_empty(queue)) printf("-1\n");
			else printf("%d\n", queue->front->data);
		}
		else if (!strcmp("back", menu)) {
			if (is_empty(queue)) printf("-1\n");
			else printf("%d\n", queue->rear->data);
		}
	}
}