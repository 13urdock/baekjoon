#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	int min = 1000000, max = -1000000;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
	}
	printf("%d %d", min, max);

	free(a);
	return 0;
}