#include <stdio.h>

int main(void) {
	int test_case;
	scanf("%d", &test_case);

	for (int i = 1; i <= test_case; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}

	return 0;
}