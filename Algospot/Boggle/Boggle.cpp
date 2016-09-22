// problem: https://algospot.com/judge/problem/read/BOGGLE
// hint: dp
// level: moderate
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool find(int i, int j, int k, const vector<string> &board, const string &word,
		  vector<string> &cache) {
	if (i < 0 || i == 5 || j < 0 || j == 5)
		return false;
	if (k == word.size())
		return true;

	char &ans = cache[i*5+j][k];
	if (ans >= 0)
		return ans;
	ans = 0;
	if (board[i][j] == word[k]) {
		for (int ii = i - 1; ii <= i + 1; ++ii) {
			for (int jj = j - 1; jj <= j + 1; ++jj) {
				if (ii == i && jj == j)
					continue;
				if (find(ii, jj, k + 1, board, word, cache))
					return ans = true;
			}
		}
	}
	return false;
}

bool find(const vector<string> &board, const string &word) {
	vector<string> cache(25, string(word.size() + 1, -1));
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (find(i, j, 0, board, word, cache))
				return true;
	return false;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		vector<string> board(5);
		for (int i = 0; i < 5; ++i)
			cin >> board[i];

		int n;
		cin >> n;
		string word;
		for (int i = 0; i < n; ++i) {
			cin >> word;
			cout << word << " " << (find(board, word)? "YES" : "NO") << endl;
		}
	}
	return 0;
}
