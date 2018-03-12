#include <iostream>
#include <string>
using namespace std;

int flip(int k, string &s) {
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n - k + 1; ++i) {
		if (s[i] == '+')
			continue;
		++ans;
		for (int j = i; j < i + k; ++j)
			s[j] = (s[j] == '+')? '-': '+';
	}
	for (int i = n - k; i < n; ++i)
		if (s[i] == '-')
			return -1;
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
