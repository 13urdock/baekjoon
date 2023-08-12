#include <stdio.h>

int main(void) {
	int price, n, sum = 0;
	scanf("%d %d", &price, &n);

	for (int i = 1; i <= n; i++) {
		int merch, num;
		scanf("%d %d", &merch, &num);
		sum += (merch * num);
	}

	if (sum == price) printf("Yes");
	else printf("No");

	return 0;
}