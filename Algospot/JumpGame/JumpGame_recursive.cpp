// problem: https://algospot.com/judge/problem/read/JUMPGAME
// hint: dp, recursive
// level: easy
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

bool possible(int i, int j, const vector<vector<int> > &board,
			  vector<vector<bool> > &visited) {
	int n = board.size();
	if (i >= n || j >= n)   return false;
	if (visited[i][j])      return false;
	if (i == n - 1 && j == n - 1)
		return true;

	visited[i][j] = true;
	return (possible(i + board[i][j], j, board, visited) ||
			possible(i, j + board[i][j], board, visited));
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;

		vector<vector<bool> > visited(n, vector<bool>(n));
		vector<vector<int> > board(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
			}
		}

		cout << ((possible(0, 0, board, visited))? "YES": "NO") << endl;
	}
	return 0;
}
