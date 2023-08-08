#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int hundred = b / 100;
    int ten = (b - hundred * 100) / 10;
    int one = b - hundred * 100 - ten * 10;

    int three = a * one;
    int four = a * ten;
    int five = a * hundred;
    int six = three + four * 10 + five * 100;

    printf("%d\n%d\n%d\n%d", three, four, five, six);

    return 0;
}