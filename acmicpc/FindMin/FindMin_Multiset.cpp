// problem: https://www.acmicpc.net/problem/11003
// hint: multiset
// level: moderate
#include <cstdio>
#include <set>

using namespace std;

#define N_MAX   (5000000)

int A[N_MAX+1];

int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);

	multiset<int> ms;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);

		auto it = ms.upper_bound(A[i]);
		ms.erase(it, ms.end());
		ms.insert(ms.end(), A[i]);

		if (i >= L && *ms.begin() == A[i-L])
			ms.erase(ms.begin());

		printf("%d ", *ms.begin());
	}
	printf("\n");

	return 0;
}
