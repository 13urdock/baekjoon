#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, x;
	scanf("%d %d", &n, &x);
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		int j;
		scanf("%d", &j);
        a[i] = j;
		if (x > a[i]) printf("%d ", a[i]);
	}

	free(a);
	return 0;
}