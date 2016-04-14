// problem: https://algospot.com/judge/problem/read/JAEHASAFE
// hint: string, kmp
// level: moderate
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getDistance(const string &target, const string &base) {
	int n = target.size(), n2 = n * 2;
	string src = base + base;
	vector<int> fail(n);
	fail[0] = -1;
	for (int i = 1; i < n; ++i) {
		int j = i;

		do {
			j = fail[j-1] + 1;
		} while (target[i] != target[j] && j > 0);
		fail[i] = (target[i] == target[j])? j : -1;
	}

	int i, j;
	for (i = j = 0; i < n2 && j < n; ++i, ++j) {
		while (src[i] != target[j] && j > 0)
			j = fail[j-1] + 1;

		if (src[i] != target[j])
			j = -1;
	}

	return i - n;
}

int getCountToUnlock(const vector<string> &dials) {
	int cnt = 0;
	for(int i = 1; i < dials.size(); ++i)
		if (i & 1)
			cnt += getDistance(dials[i-1], dials[i]);
		else
			cnt += getDistance(dials[i], dials[i-1]);
	return cnt;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;

		vector<string> dials(n + 1);
		for (int i = 0; i < n + 1; ++i)
			cin >> dials[i];

		cout << getCountToUnlock(dials) << endl;
	}

	return 0;
}
