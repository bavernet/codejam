#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int n = s.size();
		for (int i = 0, e = (n + 1) / 2; i < e; ++i)
			swap(s[i], s[n-i-1]);
		return s;
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string s;
		cin >> s;

		Solution sol;
		cout << sol.reverseString(s) << endl;
	}
	return 0;
}
