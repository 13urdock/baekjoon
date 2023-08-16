#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n[9];
	int index, max = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &n[i]);
		if (max < n[i]) {
			max = n[i];
			index = i + 1;
		}
	}
	printf("%d\n%d", max, index);

	return 0;
}