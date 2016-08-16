// problem: https://algospot.com/judge/problem/read/BRUTEFORCE
// hint: dp, math, fermat's little theorem
// level: moderate
#include <iostream>

#define N_MAX       128
#define AB_SHIFT    29
#define MOD         1000000007
#define mod(x)      (((unsigned long long)x) % MOD)

using namespace std;

int cache[N_MAX+1][AB_SHIFT+1];

void initPowCache(void) {
	for (int b = 2; b <= N_MAX; ++b) {
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

int getCases(int A, int B, int N) {
	int r = N;
	int n = B - A + 1;
	int a = mpow(N, A);
	if (r == 1)
		return n * a;

	int ans = mod(a * (mpow(r, n) - 1));
	ans = mod(ans * mpow(r - 1, MOD - 2));
	return ans;
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
