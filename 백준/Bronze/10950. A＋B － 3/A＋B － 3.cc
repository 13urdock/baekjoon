#include <stdio.h>

int main(void) {
	int a, b, test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}