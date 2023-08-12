#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	int max = (a > b && a > c) ? a : (b > a && b > c) ? b : c;

	//세 개가 같을 때, 두 개가 같을 때, 모두 다를 때 로 케이스 나누는 건 비효율적임 두 개씩 먼저 비교하며 값이 같은 게 세 개인지 두 개인지 보는 게 더.. 쉽고 편하네...
	//이런 거 할 때는 케이스? 먼저 따지기 보다 변수를 하나씩 지워나간다는 느낌으로 해보자.
	if (a == b) {
		if (b == c) printf("%d", 10000 + a * 1000);
		else printf("%d", 1000 + a * 100);
	}
	else if (b == c) {
		if (c == a) printf("%d", 10000 + b * 1000);
		else printf("%d", 1000 + b * 100);
	}
	else if (c == a) {
		if (a == b) printf("%d", 10000 + c * 1000);
		else printf("%d", 1000 + c * 100);
	}
	else printf("%d", max * 100);

	return 0;
}
