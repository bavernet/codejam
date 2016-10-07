// problem: https://algospot.com/judge/problem/read/BOARDCOVER
// hint: brute-force, implementation
// level: moderate
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int block[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
	{ { 0, 0 }, { 0, 1 }, { -1, 1 } },
};

bool check(int r, int c, int type, vector<string> &bd) {
	for (int i = 0; i < 3; ++i) {
		int x = block[type][i][0];
		int y = block[type][i][1];
		if (x + c < 0 || bd[y+r][x+c] != '.')
			return false;
	}
	return true;
}

void set(int r, int c, int type, char ch, vector<string> &bd) {
	for (int i = 0; i < 3; ++i) {
		int x = block[type][i][0];
		int y = block[type][i][1];
		bd[y+r][x+c] = ch;
	}
}

int lay(int r, int c, int cnt, int type, vector<string> &bd) {
	int h = bd.size() - 1, w = bd[0].size() - 1;
	int ans = 0;
	if (!check(r, c, type, bd))
		return 0;

	cnt -= 3;
	if (!cnt)
		return 1;
	set(r, c, type, '*', bd);

	for (int i = r; i < h; ++i) {
		for (int j = ((i == r)? c: 0); j < w; ++j) {
			if (bd[i][j] == '.') {
				for (int t = 0; t < 4; ++t)
					ans += lay(i, j, cnt, t, bd);
				set(r, c, type, '.', bd);
				return ans;
			}
		}
	}
	return ans;
}

int cases(int cnt, vector<string> &bd) {
	if (cnt % 3) return 0;
	if (!cnt)    return 1;

	int h = bd.size() - 1, w = bd[0].size() - 1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (bd[i][j] == '.') {
				int ans = 0;
				for (int t = 0; t < 4; ++t)
					ans += lay(i, j, cnt, t, bd);
				return ans;
			}
		}
	}
	return 0;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int h, w, cnt = 0;
		cin >> h >> w;
		vector<string> bd(h);
		for (int i = 0; i < h; ++i) {
			cin >> bd[i];
			cnt += count(bd[i].begin(), bd[i].end(), '.');
			bd[i].push_back('x');
		}
		bd.push_back(string(w+1, 'x'));
		cout << cases(cnt, bd) << endl;
	}
	return 0;
}
