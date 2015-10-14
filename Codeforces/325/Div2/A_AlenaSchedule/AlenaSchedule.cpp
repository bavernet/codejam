// problem: http://codeforces.com/contest/586/problem/A
// hint: implementation
// level: easy
#include <iostream>

#define MAX_N   (100)

using namespace std;

bool ai[MAX_N+2];

int main(void) {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> ai[i];

	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(ai[i] || (ai[i-1] && ai[i+1]))
			++cnt;

	cout << cnt << endl;

	return 0;
}
