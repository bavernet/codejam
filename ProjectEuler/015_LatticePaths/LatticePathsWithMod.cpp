// problem: https://www.hackerrank.com/contests/projecteuler/challenges/euler015
// hint: dp
// level: easy
#include <iostream>

#define MAX_T   (1000)
#define MAX_N   (500)
#define MAX_M   (500)
#define MOD     (1000000007)

using namespace std;

int cache[MAX_N+2][MAX_M+2] = { 0, };

void findAllPaths(int n, int m) {
	for(int i = 1; i < n + 2; ++i)
		cache[i][1] = 1;
	for(int j = 1; j < m + 2; ++j)
		cache[1][j] = 1;
	for(int i = 2; i < n + 2; ++i)
		for(int j = 2; j < m + 2; ++j)
			cache[i][j] = (cache[i-1][j] + cache[i][j-1]) % MOD;
}

int solve(int n, int m) {
	return cache[n+1][m+1];
}

int main(void) {
	int nTests;
	cin >> nTests;
	findAllPaths(MAX_N, MAX_M);
	while(nTests--) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}
	return 0;
}
