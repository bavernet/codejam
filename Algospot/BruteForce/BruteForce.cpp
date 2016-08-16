// problem: https://algospot.com/judge/problem/read/BRUTEFORCE
// hint: divide-and-conquer
// level: moderate
#include <iostream>

#define MOD         1000000007
#define mod(x)      (((unsigned long long)x) % MOD)

using namespace std;

int mpow(int base, int exp) {
	int ans = 1;
	if (base == 1 || exp == 0)
		return ans;
	if (exp == 1)
		return base;
	if (exp & 0x01)
		return mod(base * mpow(base, exp - 1));

	int half = mpow(base, exp / 2);
	return mod(half * half);
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
	while (nTests--) {
		int A, B, N;
		cin >> A >> B >> N;
		cout << getCases(A, B, N) << endl;
	}

	return 0;
}
