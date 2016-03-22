// problem: https://algospot.com/judge/problem/read/RATIO
// hint: math
// level: easy
#include <stdio.h>
#include <math.h>

int getCount(long long total, long long win) {
	int needs, ratio = 100 * win / total;
	if(ratio >= 99)
		return -1;

	needs = (ratio + 1) * total - 100 * win;
	return ceil((double)needs / (99 - ratio));
}

int main(void) {
	int nTests;
	scanf("%d", &nTests);
	while(nTests--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", getCount(n, m));
	}

	return 0;
}
