// problem: https://www.acmicpc.net/problem/11003
// hint: greedy, queue
// level: moderate
#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

#define N_MAX   (5000000)

int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);

	deque<pair<int,int> > q;
	for (int i = 0; i < N; ++i) {
		pair<int,int> a(i, 0);
		scanf("%d", &a.second);

		while (!q.empty() && q.back().second >= a.second)
			q.pop_back();
		q.push_back(a);

		if (i >= L && q.front().first == i - L)
			q.pop_front();

		printf("%d ", q.front().second);
	}
	printf("\n");

	return 0;
}
