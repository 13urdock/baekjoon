#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    long long a, b, c; //범위가 1 < a, b, c <= 10^12 이기 때문에 long long 자료형을 써야함
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld", a + b + c);

    return 0;
}
