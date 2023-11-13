#include <stdio.h>
#include <stdlib.h>

void swp(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc((N * N + 1) * sizeof(int));
	int size = 0;
	for (int i = 0; i < N * N; i++) {
		int n;
		scanf("%d", &n);

		size++;
		arr[size] = n;
		int j = size;
		while ((j != 1) && (n > arr[j / 2])) {
			arr[j] = arr[j / 2];
			j /= 2;
		}
		arr[j] = n;
	}

	for (int i = 0; i < N - 1; i++) {
		int parent = 1;
		int child = 2;
		
		arr[1] = arr[size];
		size--;
		while (child <= size) {
			if (arr[child] < arr[child + 1])
				child++;
			if (arr[parent] < arr[child]) {
				swp(&arr[parent], &arr[child]);
			}
			else break;
			parent = child;
			child *= 2;
		}
	}
	int removed = arr[1];

	printf("%d", removed);
	
	free(arr);
	return 0;
}