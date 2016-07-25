// problem: https://www.acmicpc.net/problem/11003
// hint: greedy
// level: moderate
#include <cstdio>
#include <deque>

using namespace std;

#define N_MAX   (5000000)

int A[N_MAX+1];

int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);

	deque<int> q;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);

		while (!q.empty() && q.back() > A[i])
			q.pop_back();
		q.push_back(A[i]);

		if (i >= L && q.front() == A[i-L])
			q.pop_front();

		printf("%d ", q.front());
	}
	printf("\n");

	return 0;
}
