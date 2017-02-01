// problem: http://codeforces.com/contest/761/problem/B
// hint: math, brute-force
// level: easy
#include <iostream>
#include <vector>

using namespace std;

static inline bool equals(const vector<int> &a, const vector<int> &b,
						  int offset, int L) {
	int n = a.size();
	int d = b[offset] - a[0];
	for (int i = 0, j = offset; i < n; ++i, j = (j + 1) % n)
		if ((a[i] + d - b[j]) % L)
			return false;
	return true;
}

bool equals(vector<int> &a, vector<int> &b, int L) {
	int n = b.size();
	for (int i = 0; i < n; ++i)
		if (equals(a, b, i, L))
			return true;
	return false;
}

int main(void) {
	cout.sync_with_stdio(false);
	int n, L;
	cin >> n >> L;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	cout << (equals(a, b, L)? "YES": "NO") << endl;
	return 0;
}
