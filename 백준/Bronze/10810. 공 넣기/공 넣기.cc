#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int* bascket = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < m; i++) {
		int j, k, l;
		scanf("%d %d %d", &j, &k, &l);
		for (int t = j; t <= k; t++)
			bascket[t -1] = l;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", bascket[i]);

	free(bascket);
	return 0;
}