#include <iostream>
#include <vector>

#define MOD         (20091101)
#define mod(x)      ((x) % (MOD))
#define idx(i)      ((i) - 2)

using namespace std;

enum { NOT_FOUND, INIT };

inline int comb(long long n) {
	return mod(n * (n - 1) / 2);
}

int solve1(const vector<int> &ps, int k) {
	int ans = 0, n = ps.size();
	vector<int> cnt(k);
	cnt[0] = 1;
	for (int i = 0; i < n; ++i)
		++cnt[ps[i]];
	for (int i = 0; i < k; ++i)
		ans = mod(ans + comb(cnt[i]));
	return ans;
}

int solve2(const vector<int> &ps, int k) {
	int n = ps.size();
	vector<int> prev(k, NOT_FOUND);
	vector<int> dp(n + 2);
	dp[NOT_FOUND] = -1;
	prev[0] = INIT;
	for (int i = 2, e = n + 2; i < e; ++i) {
		int s = ps[idx(i)];
		dp[i] = max(dp[i-1], dp[prev[s]] + 1);
		prev[s] = i;
	}
	return dp[n + 1];
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;

	while (nTests--) {
		int n, k, d;
		cin >> n >> k;

		vector<int> ps(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> d;
			sum = (sum + d) % k;
			ps[i] = sum;
		}

		cout << solve1(ps, k) << " " << solve2(ps, k) << endl;
	}

	return 0;
}
