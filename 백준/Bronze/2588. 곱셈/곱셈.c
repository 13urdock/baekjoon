#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int hundred = b / 100; //b 의 백의 자리 숫자
    int ten = (b - hundred * 100) / 10; //b 의 십의 자리 숫자
    int one = b - hundred * 100 - ten * 10; //b 의 일의 자리 숫자

    int three = a * one;
    int four = a * ten;
    int five = a * hundred;
    int six = three + four * 10 + five * 100;

    printf("%d\n%d\n%d\n%d", three, four, five, six);

    return 0;
}
