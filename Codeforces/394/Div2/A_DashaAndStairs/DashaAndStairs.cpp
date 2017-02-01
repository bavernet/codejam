// problem: http://codeforces.com/contest/761/problem/A
// hint: math
// level: easy
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	cout.sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if ((a == 0 && b == 0) || (abs(a - b) > 1))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
