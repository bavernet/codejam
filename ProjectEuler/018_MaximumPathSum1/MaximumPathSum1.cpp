// problem: https://www.hackerrank.com/contests/projecteuler/challenges/euler018
// hint: dp
// level: easy
#include <iostream>
#include <algorithm>

#define MAX_T   (10)
#define MAX_N   (15)

using namespace std;

int sum[MAX_N+1][MAX_N+1];

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n, num;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= i; ++j) {
				cin >> num;
				sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + num;
			}
		}
		cout << (*max_element(sum[n], sum[n] + n + 1)) << endl;
	}

	return 0;
}
