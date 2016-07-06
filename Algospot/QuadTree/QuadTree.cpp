// problem: https://algospot.com/judge/problem/read/QUADTREE
// hint: divide and conquer
// level: easy
#include <iostream>
#include <string>

using namespace std;

string reverse(const string &s, int &cnt) {
	if (s[0] != 'x')
		return s;

	string quad[4];
	int scnt = 1;
	for (int i = 0; i < 4; ++i, ++cnt) {
		if (s[i+scnt] != 'x') {
			quad[i] += s[i+scnt];
		} else {
			quad[i] = reverse(s.substr(i + scnt), scnt);
		}
	}
	cnt += scnt - 1;
	return "x" + quad[2] + quad[3] + quad[0] + quad[1];
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string qtree;
		int cnt = 0;
		cin >> qtree;
		cout << reverse(qtree, cnt) << endl;
	}

	return 0;
}
