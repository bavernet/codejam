// problem: https://algospot.com/judge/problem/read/WILDCARD
// hint: dp
// level: easy
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool match(int i, int j, const string &pattern, const string &filename,
		   vector<string> &cache) {
	if (i == pattern.size())
		return j == filename.size();
	if (j == filename.size())
		return pattern[i] == '*' && i + 1 == pattern.size();
	char &ans = cache[i][j];
	if (ans >= 0)
		return ans;
	ans = 0;
	if (pattern[i] == '*')
		return (ans = match(i, j + 1, pattern, filename, cache) || match(i + 1, j, pattern, filename, cache));
	if (pattern[i] == '?' || pattern[i] == filename[j])
		return (ans = match(i + 1, j + 1, pattern, filename, cache));
	return ans;
}

void filter(const string &pattern, const vector<string> &files,
			set<string> &ans) {
	for (int i = 0; i < files.size(); ++i) {
		vector<string> cache(pattern.size(), string(files[i].size() + 1, -1));
		if (match(0, 0, pattern, files[i], cache))
			ans.insert(files[i]);
	}
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string pattern;
		cin >> pattern;

		int n;
		cin >> n;
		vector<string> files(n);
		for (int i = 0; i < n; ++i)
			cin >> files[i];

		set<string> matched;
		filter(pattern, files, matched);
		for (auto &s : matched)
			cout << s << endl;
	}
	return 0;
}
