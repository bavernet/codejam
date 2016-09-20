// problem: https://algospot.com/judge/problem/read/JUMPGAME
// hint: dp, stack
// level: easy
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

bool possible(const vector<vector<int> > &board) {
	int n = board.size();
	vector<vector<bool> > visited(n, vector<bool>(n));
	stack<pair<int,int> > st;
	st.push(make_pair(0, 0));
	while (!st.empty()) {
		pair<int,int> p = st.top();
		st.pop();
		int i = p.first, j = p.second;

		if (visited[i][j])
			continue;
		visited[i][j] = true;

		if (i == n - 1 && j == n - 1)
			return true;

		int ii = i + board[i][j];
		if (ii < n)
			st.push(make_pair(ii, j));

		int jj = j + board[i][j];
		if (jj < n)
			st.push(make_pair(i, jj));
	}
	return false;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;

		vector<vector<int> > board(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
			}
		}

		cout << ((possible(board))? "YES": "NO") << endl;
	}
	return 0;
}
