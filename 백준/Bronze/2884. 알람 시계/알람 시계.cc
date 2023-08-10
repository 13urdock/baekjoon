#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, m;
	scanf("%d", &h);
	scanf("%d", &m);

	if (m < 45) {
		if (h == 0) h = 23;
		else h--;
		m += 15;
	}
	else m -= 45;
	
	printf("%d %d", h, m);
	
	return 0;
}