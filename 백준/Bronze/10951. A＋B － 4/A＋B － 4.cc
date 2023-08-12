#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    //이 문제에서는 테스트 케이스를 입력받지 않음. 인풋들을 넣고 그게 끝날 때까지 출력하는 ? 거라? end of file까지 while문 돌리는 거
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
        printf("%d\n", a + b);

    return 0;
}
