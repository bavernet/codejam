// problem: https://algospot.com/judge/problem/read/BRUTEFORCE
// hint: divide-and-conquer, dp
// level: moderate
#include <iostream>

#define N_MAX       128
#define AB_SHIFT    27
#define MOD         1000000007
#define mod(x)      (((unsigned long long)x) % MOD)

using namespace std;

int cache[N_MAX+1][AB_SHIFT+1];

void initPowCache(void) {
	for (int b = 1; b <= N_MAX; ++b) {
		cache[b][0] = b;
		for (int e = 1; e <= AB_SHIFT; ++e)
			cache[b][e] = mod(cache[b][e-1] * cache[b][e-1]);
	}
}

int mpow(int base, int exp) {
	int ans = 1;
	if (base == 1)
		return ans;

	while (exp) {
		int x = exp & -exp;
		int e = __builtin_ctz(x);
		ans = mod(ans * cache[base][e]);
		exp ^= x;
	}
	return ans;
}

int getCases(int a, int b, int n) {
	if (a == b)
		return mpow(n, b);

	int cnt = b - a + 1;
	int remain = 0;
	if (cnt & 0x01) {
		remain = mpow(n, b);
		--b;
	}

	int half = getCases(a, (a + b - 1) / 2, n);
	int common = mpow(n, (b - a + 1) / 2) + 1;
	return mod(common * half + remain);
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	initPowCache();
	while (nTests--) {
		int A, B, N;
		cin >> A >> B >> N;
		cout << getCases(A, B, N) << endl;
	}

	return 0;
}
