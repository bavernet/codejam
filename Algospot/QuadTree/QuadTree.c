// problem: https://algospot.com/judge/problem/read/QUADTREE
// hint: divide and conquer
// level: easy
#include <stdio.h>
#include <string.h>

#define MAX_N   (1000)

char qtree[MAX_N+1];
char tmp[MAX_N+1];

void swap(char *l, char *r, int lenL, int lenR) {
	memcpy(tmp, l, lenL);
	memcpy(l, r, lenR);
	memcpy(l + lenR, tmp, lenL);
}

char *reverse(char **qt) {
	char *ans = *qt;
	if (**qt != 'x') {
		++(*qt);
		return ans;
	}

	int i;
	char *s[4];
	++(*qt);
	for (i = 0; i < 4; ++i)
		s[i] = reverse(qt);
	swap(s[0], s[2], s[2] - s[0], *qt - s[2]);
	return ans;
}

int main(void) {
	int nTests;

	scanf("%d", &nTests);
	while (nTests--) {
		char *qt = qtree;
		scanf("%s", qt);
		printf("%s\n", reverse(&qt));
	}

	return 0;
}
