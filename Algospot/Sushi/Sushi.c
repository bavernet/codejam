// problem: https://algospot.com/judge/problem/read/SUSHI
// hint: dp
// level: easy
#include <stdio.h>

#define MAX_N       (20)
#define CACHE_SIZE  (0xFF)
#define idx(i)      ((i) & CACHE_SIZE)

int n, m;
int price[MAX_N], pref[MAX_N];
int cache[CACHE_SIZE+1];

int max(int a, int b) {
	return a > b ? a : b;
}

int getMaxScore(int money) {
	int i, j, score;
	cache[0] = 0;
	for (i = 1; i <= money; ++i) {
		score = 0;
		for (j = 0; j < n; ++j)
			if (price[j] <= i)
				score = max(score, cache[idx(i - price[j])] + pref[j]);
		cache[idx(i)] = score;
	}
	return cache[idx(money)];
}

int main(void) {
	int nTests, i;
	scanf("%d", &nTests);
	while (nTests--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; ++i) {
			scanf("%d %d", &price[i], &pref[i]);
			price[i] /= 100;
		}
		printf("%d\n", getMaxScore(m / 100));
	}
	return 0;
}
