#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

inline int getBit(char c) {
	return 1 << (c - 'a');
}

long long getEvenSubstring(const string &s) {
	long long cnt = 0;
	int n = s.size();
	int x = 0;
	map<int,int> m;
	for (int i = 0; i < n; ++i) {
		x ^= getBit(s[i]);
		cnt += m[x]++;
	}
	cnt += m[0];

	return cnt;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		string s;
		cin >> s;
		cout << getEvenSubstring(s) << endl;
	}

	return 0;
}
