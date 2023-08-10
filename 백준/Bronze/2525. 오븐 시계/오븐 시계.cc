#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, m, time;
	scanf("%d %d", &h, &m);
	scanf("%d", &time);

	h += time / 60;
	if (h > 23) h -= 24;
	m += time % 60;
	
	if (m > 59) {
		if (h == 23) h = 0;
		else h++;
		m -= 60;
	}

	printf("%d %d", h, m);

	return 0;
}