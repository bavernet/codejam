// problem: https://algospot.com/judge/problem/read/QUADTREE
// hint: divide and conquer
// level: easy
#include <iostream>
#include <string>

using namespace std;

string reverse(const string &qt) {
	if (qt[0] != 'x')
		return qt;

	string s[4];
	int cnt = 1;
	for (int i = 0; i < 4; ++i) {
		s[i] = (qt[cnt] != 'x')? string(1, qt[cnt]): reverse(qt.substr(cnt));
		cnt += s[i].size();
	}
	return "x" + s[2] + s[3] + s[0] + s[1];
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string qtree;
		cin >> qtree;
		cout << reverse(qtree) << endl;
	}

	return 0;
}
