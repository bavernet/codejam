// problem: https://algospot.com/judge/problem/read/PI
// hint: dp
// level: easy
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

bool level1(int start, int len, const string &seq) {
	for (int i = start + 1, e = start + len; i < e; ++i)
		if (seq[i-1] != seq[i])
			return false;
	return true;
}

bool level2(int start, int len, const string &seq) {
	int diff = seq[start] - seq[start+1];
	for (int i = start + 2, e = start + len; i < e; ++i)
		if (seq[i-1] - seq[i] != diff)
			return false;
	return (diff == 1 || diff == -1);
}

bool level4(int start, int len, const string &seq) {
	char cs[2];
	cs[start & 0x01] = seq[start];
	cs[!(start & 0x01)] = seq[start+1];
	for (int i = start + 2, e = start + len; i < e; ++i)
		if (cs[i & 0x01] != seq[i])
			return false;
	return true;
}

bool level5(int start, int len, const string &seq) {
	int diff = seq[start] - seq[start+1];
	for (int i = start + 2, e = start + len; i < e; ++i)
		if (seq[i-1] - seq[i] != diff)
			return false;
	return true;
}

int getLevel(int start, int len, const string &seq) {
	if (level1(start, len, seq))
		return 1;
	if (level2(start, len, seq))
		return 2;
	if (level4(start, len, seq))
		return 4;
	if (level5(start, len, seq))
		return 5;
	return 10;
}

int getMinLevelSum(int i, const string &seq, vector<int> &dp) {
	int n = seq.size();
	if (i == n)     return 0;
	if (i + 3 > n)  return 123456;
	int &ans = dp[i];
	if (ans)
		return ans;

	ans = INT_MAX;
	for (int len = 3; len <= 5; ++len)
		ans = min(ans, getLevel(i, len, seq) + getMinLevelSum(i + len, seq, dp));
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string seq;
		cin >> seq;
		vector<int> dp(seq.size());
		cout << getMinLevelSum(0, seq, dp) << endl;
	}
	return 0;
}
