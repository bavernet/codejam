#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string s, string w) {
	int n = s.size();
	int k = w.size();
	vector<int> lmt(k, 0);
	for (int i = 1; i < k; ++i) {
		int j = lmt[i-1];
		while (j > 0 && w[i] != w[j])
			j = lmt[j-1];
		if (w[i] == w[j])
			lmt[i] = j + 1;
	}

	for (int i = 0, j = 0; i < n; ++i) {
		while (j > 0 && s[i] != w[j])
			j = lmt[j-1];
		if (s[i] == w[j])
			++j;
		if (j == k)
			return i - k + 1;
	}
	return -1;
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
