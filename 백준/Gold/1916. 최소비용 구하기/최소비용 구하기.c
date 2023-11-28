#include <stdio.h>
#include <stdlib.h>
#define MAXCITY 1001
#define INF 100000000

typedef struct Road {
	int size;
	int weight[MAXCITY][MAXCITY];
}Road;

int distance[MAXCITY];
int selected[MAXCITY];

Road* create_road(int size) {
	Road* r = (Road*)malloc(sizeof(Road));
	r->size = size;
	for (int i = 0; i < MAXCITY; i++) {
		for (int j = 0; j < MAXCITY; j++) {
			r->weight[i][j] = INF;
		}
	}
	return r;
}

void insert_road(Road* r, int start, int end, int weight) {
	if (r->weight[start][end] > weight)
		r->weight[start][end] = weight;
}

int smallest_index(Road* r) {
	int min = INF;
	int index = 0;
	for (int i = 1; i <= r->size; i++) {
		if (distance[i] < min && !selected[i]) {
			min = distance[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(Road* r, int start) {
	for (int i = 1; i <= r->size; i++) {
		distance[i] = r->weight[start][i];
	}
	selected[start] = 1;
	selected[0] = 1;
	for (int i = 1; i <= r->size - 1; i++) {
		int current = smallest_index(r);
		selected[current] = 1;
		for (int j = 1; j <= r->size; j++) {
			if (!selected[j]) {
				if (distance[current] + r->weight[current][j] < distance[j]) {
					distance[j] = distance[current] + r->weight[current][j];
				}
			}
		}
	}
}

int main() {
	int cities, buses;
	scanf("%d", &cities); scanf("%d", &buses);
	Road* r = create_road(cities);

	for (int i = 0; i < buses; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		insert_road(r, s, e, w);
	}
	int start, end;
	scanf("%d %d", &start, &end);
	if (start == end) {
		printf("0");
		return 0;
	}
	dijkstra(r, start);
	printf("%d", distance[end]);
	return 0;
}
