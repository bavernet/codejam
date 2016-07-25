// problem: https://www.acmicpc.net/problem/11003
// hint: greedy, queue, binary search
// level: moderate
#include <stdio.h>
#define N_MAX   (5000000)

int A[N_MAX], Q[N_MAX];
int f = 0, b = 0;

static inline void push_back(int a) {
	Q[b++] = a;
}

static inline void pop_back(void) {
	--b;
}

static inline void pop_front(void) {
	++f;
}

static inline int back(void) {
	return Q[b-1];
}

static inline int front(void) {
	return Q[f];
}

static inline int empty(void) {
	return f >= b;
}

static inline void erase(int a) {
	int left = f, right = b;
	if (empty())
		return ;

	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (a < Q[mid]) {
			right = mid;
		} else {
			left = mid;
		}
	}

	b = left + (Q[left] <= a);
}

int main(void) {
	int N, L, i;
	scanf("%d %d", &N, &L);

	for (i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
		erase(A[i]);
		push_back(A[i]);
		if (i >= L && front() == A[i-L])
			pop_front();

		printf("%d ", front());
	}
	printf("\n");

	return 0;
}
