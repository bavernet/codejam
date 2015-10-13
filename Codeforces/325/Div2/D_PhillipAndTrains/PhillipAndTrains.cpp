// problem: http://codeforces.com/contest/586/problem/D
// hint: backtracking, dp
// level: easy
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#define MAX_N   (100)
#define MAX_K   (26)

using namespace std;

bool visit[3][MAX_N+1];

bool solve(const vector<string> &tunnel, int n, int si, int sj) {
	if(sj >= n)         return true;
	if(visit[si][sj])   return false;
	visit[si][sj] = true;

	if(tunnel[si][sj] != '.' || tunnel[si][sj+1] != '.')
		return false;

	if(si - 1 >= 0 && tunnel[si-1][sj+1] == '.')
		if(solve(tunnel, n, si - 1, sj + 3))
			return true;

	if(si + 1 < 3 && tunnel[si+1][sj+1] == '.')
		if(solve(tunnel, n, si + 1, sj + 3))
			return true;

	return solve(tunnel, n, si, sj + 3);
}

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n, k, si = 0;
		cin >> n >> k;

		vector<string> tunnel;
		for(int i = 0; i < 3; ++i) {
			string row;
			cin >> row;
			if(row[0] == 's') {
				si = i;
				row[0] = '.';
			}
			row.push_back('.');
			tunnel.push_back(row);
		}

		memset(visit, 0, sizeof(visit));
		cout << ((solve(tunnel, n, si, 0))? "YES": "NO") << endl;
	}

	return 0;
}
