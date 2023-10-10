#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

Node* create_node(const char data){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void preorder(Node* node){
	if (node == NULL) return;
	printf("%c", node->data);
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node* node){
	if (node == NULL) return;
	inorder(node->left);
	printf("%c", node->data);
	inorder(node->right);
}

void postorder(Node* node){
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	printf("%c", node->data);
}

void add_nodes(Node* node, const char parent, const char left, const char right){
	if (node == NULL) return;
	if (node->data == parent){
		if (left != '.')
			node->left = create_node(left);
		if (right != '.')
			node->right = create_node(right);
		return;
	}
	add_nodes(node->left, parent, left, right);
	add_nodes(node->right, parent, left, right);
}

int main(){
	Node* root = create_node('A');
	int nodes;
	scanf("%d", &nodes);
	for(int i = 0; i < nodes; i++){
		char d1, d2, d3;
		scanf(" %c %c %c", &d1, &d2, &d3);
		add_nodes(root, d1, d2, d3);
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	return 0;
}