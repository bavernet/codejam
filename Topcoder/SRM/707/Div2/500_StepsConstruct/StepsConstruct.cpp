#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Step {
	int k, x, y;
	Step(int _k, int _x, int _y): k(_k), x(_x), y(_y) { }

	bool operator <(const Step &rhs) const {
		if (k == rhs.k)
			return (y == rhs.y)? (x < rhs.x): (y < rhs.y);
		return k < rhs.k;
	}
};

class StepsConstruct {
private:
	int move[4][2] = {
		{ -1, 0 }, { 1, 0 },
		{ 0, -1 }, { 0, 1 },
	};
	char dir[4]  = { 'L', 'R', 'U', 'D' };

	bool valid(const vector<string> &board, int x, int y) {
		if (y < 0 || y >= (int)board.size() || x < 0 || x >= (int)board[y].size())
			return false;
		return board[y][x] != '#';
	}
public:
	string construct(vector<string> board, int k) {
		if (board.empty())
			return "";

		int n = board.size(), m = board.back().size();
		if (board[0][0] == '#' || board[n-1][m-1] == '#')
			return "";

		priority_queue<Step> pq;
		vector<vector<int> > d(n, vector<int>(m, -1));
		vector<string> path(n, string(m, ' '));
		vector<vector<vector<int> > > prev(n, vector<vector<int> >(m, vector<int>(2, -1)));
		vector<vector<bool> > visited(n, vector<bool>(m));
		pq.push(Step(k, 0, 0));
		d[0][0] = k;
		while (!pq.empty()) {
			Step step = pq.top();
			pq.pop();
			if (visited[step.y][step.x])
				continue;
			visited[step.y][step.x] = true;
			for (int i = 0; i < 4; ++i) {
				int nx = step.x + move[i][0], ny = step.y + move[i][1];
				if (valid(board, nx, ny)) {
					if (d[ny][nx] < d[step.y][step.x] - 1) {
						d[ny][nx] = d[step.y][step.x] - 1;
						prev[ny][nx] = { step.x, step.y };
						path[ny][nx] = dir[i];
						pq.push(Step(d[ny][nx], nx, ny));
					}
				}
			}
		}

		if (d[n-1][m-1] < 0)
			return "";

		if (d[n-1][m-1] & 1)
			return "";

		string ans;
		int cx = m - 1, cy = n - 1;
		while (cx != 0 || cy != 0) {
			ans.push_back(path[cy][cx]);
			int nx = prev[cy][cx][0];
			int ny = prev[cy][cx][1];
			cx = nx, cy = ny;
		}
		reverse(ans.begin(), ans.end());
		char last = ans.back();
		for (int rs = d[n-1][m-1]; rs > 0; rs -= 2) {
			if (last == 'D') {
				ans.push_back('U');
				ans.push_back('D');
			} else {
				ans.push_back('L');
				ans.push_back('R');
			}
		}
		return ans;
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<string> board(n);
		for (int i = 0; i < n; ++i)
			cin >> board[i];
		StepsConstruct sol;
		cout << sol.construct(board, k) << endl;
	}
	return 0;
}
