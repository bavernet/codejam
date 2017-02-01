// problem: http://codeforces.com/contest/761/problem/C
// hint: brute-force
// level: easy
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

#define INVALID (1234567)

int count(const vector<string> &ps) {
	int n = ps.size(), m = ps.front().size();
	vector<int> digit(n, INVALID), alpha(n, INVALID), symbol(n, INVALID);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (isdigit(ps[i][j])) {
				digit[i] = min(digit[i], min(j, m - j));
			} else if (isalpha(ps[i][j])) {
				alpha[i] = min(alpha[i], min(j, m - j));
			} else {
				symbol[i] = min(symbol[i], min(j, m - j));
			}
		}
	}
	int ans = INVALID;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			for (int k = 0; k < n; ++k) {
				if (k == i || k == j) continue;
				ans = min(ans, digit[i] + alpha[j] + symbol[k]);
			}
		}
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> ps(n);
	for (int i = 0; i < n; ++i)
		cin >> ps[i];
	cout << count(ps) << endl;
	return 0;
}
