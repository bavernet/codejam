// problem: http://codeforces.com/contest/716/problem/A
// hint: greedy
// level: easy
#include <iostream>
#include <vector>

using namespace std;

int countWords(const vector<int> &num, int limit) {
	int ans = 1, n = num.size();
	for (int i = 1; i < n; ++i) {
		if (num[i] - num[i-1] > limit) {
			ans = 1;
		} else {
			++ans;
		}
	}
	return ans;
}

int main(void) {
	int n, c;
	cin >> n >> c;

	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	cout << countWords(num, c) << endl;
	return 0;
}
