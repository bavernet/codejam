// problem: https://algospot.com/judge/problem/read/RATIO
// hint: math
// level: easy
#include <iostream>
#include <cmath>

using namespace std;

int getCount(int64_t total, int64_t win) {
	int ratio = 100 * win / total;
	if(ratio >= 99)
		return -1;

	int needs = (ratio + 1) * total - 100 * win;
	return ceil((double)needs / (99 - ratio));
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n, m;
		cin >> n >> m;
		cout << getCount(n, m) << endl;
	}

	return 0;
}
