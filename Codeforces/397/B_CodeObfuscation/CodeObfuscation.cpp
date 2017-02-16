// problem: http://codeforces.com/contest/765/problem/B
// hint: implementation
// level: easy
#include <iostream>
#include <string>

using namespace std;

bool correct(const string &s) {
	int n = s.size();
	char c = 'a';
	for (auto symbol : s) {
		if (symbol == c)
			++c;
		else if (symbol > c)
			return false;
	}
	return true;
}

int main(void) {
	cout.sync_with_stdio(false);
	string s;
	cin >> s;
	cout << (correct(s)? "YES": "NO") << endl;
	return 0;
}
