#include <iostream>

#define MAX_T   (1000)
#define MAX_N   (500)
#define MAX_M   (500)
#define MOD     (1000000007)

using namespace std;

int cache[MAX_N+1][MAX_M+1] = { 0, };

int solve(int n, int m) {
	if(n < 0 || m < 0)
		return 0;

	if(n == 0 || m == 0)
		return 1;

	int &nPaths = cache[n+1][m+1];
	if(nPaths > 0)
		return nPaths;

	return (solve(n - 1, m) + solve(n, m - 1)) % MOD;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}
	return 0;
}
