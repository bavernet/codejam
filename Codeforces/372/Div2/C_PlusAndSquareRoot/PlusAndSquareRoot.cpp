// problem: http://codeforces.com/contest/716/problem/C
// hint: math
// level: easy
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void walk(int64_t n, vector<int64_t> &steps) {
	int64_t x = 2;
	for (int64_t lv = 1; lv <= n; ++lv) {
		int64_t unit = lv * (lv + 1);
		int64_t next = unit;
		while (next < sqrtl(x))
			next += unit;

		int64_t cnt = lv * (lv + 1) * (lv + 1) - (x / lv);
		x = next;
		steps.push_back(cnt);
	}
}

int main(void) {
	cout.sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int64_t> steps;
	walk(n, steps);

	for (int i = 0; i < n; ++i)
		cout << steps[i] << endl;

	return 0;
}
