#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[201] = { 0 };

    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);
        arr[number + 100]++;
    }

    int pick;
    scanf("%d", &pick);

    printf("%d", arr[pick + 100]);
    return 0;
}
