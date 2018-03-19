#include <iostream>
#include <string>
#include <queue>
using namespace std;

int flip(int k, string &s) {
	int n = s.size();
	int ans = 0;
	queue<int> q;
	char happy = '+';
	for (int i = 0; i < n; ++i) {
		if (q.size() && q.front() == i) {
			q.pop();
			happy = (happy == '+')? '-': '+';
		}

		if (s[i] == happy)
			continue;

		if (i > n - k)
			return -1;

		++ans;
		happy = (happy == '+')? '-': '+';
		q.push(i + k);
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int i = 1; i <= nTests; ++i) {
		int k;
		string s;
		cin >> s >> k;
		int ans = flip(k, s);
		if (ans >= 0)
			cout << "Case #" << i << ": " << ans << '\n';
		else
			cout << "Case #" << i << ": IMPOSSIBLE\n";
	}
	return 0;
}
