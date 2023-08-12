#include <stdio.h>

int main(void) {
	int line;
	scanf("%d", &line);

	for (int i = 1; i <= line; i++) {
		for (int k = 1; k <= line - i; k++)
			printf(" ");
		for (int j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}