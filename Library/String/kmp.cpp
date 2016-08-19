#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string s, string w) {
	int n = s.size();
	int k = w.size();
	int i, j;
	vector<int> lmt(k, 0);
	for (i = 1; i < k; ++i)
		if (w[lmt[i-1]] == w[i])
			lmt[i] = lmt[i-1] + 1;

	for (i = 0, j = 0; i < n && j < k; ++i, ++j) {
		while (j > 0 && s[i] != w[j])
			j = lmt[j-1];
		if (s[i] != w[j])
			--j;
	}

	return (j == k)? (i - k): -1;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string sentence, word;
		cin >> sentence >> word;
		cout << kmp(sentence, word) << endl;
	}

	return 0;
}
