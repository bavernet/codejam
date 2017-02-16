// problem: http://codeforces.com/contest/765/problem/A
// hint: implementation
// level: easy
#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d", &n);
	char s[4], d[4], first[4];
	scanf("%s", first);
	first[3] = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%3s->%3s", s, d);
		s[3] = 0, d[3] = 0;
		if (!strncmp(first, s, 3))
			++cnt;
		if (!strncmp(first, d, 3))
			++cnt;
	}
	if (cnt % 2)
		printf("contest\n");
	else
		printf("home\n");
	return 0;
}
