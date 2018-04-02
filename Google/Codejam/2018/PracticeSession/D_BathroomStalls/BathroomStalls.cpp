#include <iostream>
#include <utility>
using namespace std;

static inline long long mask(unsigned long long k) {
	if (k < 2)
		return 0;
	return (~0ULL) >> (__builtin_clzll(k) + 1);
}

pair<long long, long long> stall(long long n, long long k) {
	long long q = mask(k);
	long long big = (n - q) % (q + 1);
	long long unit = (n - q) / (q + 1);
	if (k - q > big)
		--unit;
	long long left = unit / 2;
	long long right = unit - left;
	return make_pair(max(left, right), min(left, right));
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		long long n, k;
		cin >> n >> k;
		const pair<long long, long long> &ans = stall(n, k);
		cout << "Case #" << t << ": " << ans.first << ' ' << ans.second << '\n';
	}
	return 0;
}
