#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(const string &word, const string &txt) {
	int n = txt.size();
	int k = word.size();
	vector<int> lmt(k);
	for (int i = 1, j = 0; i < k; ++i) {
		while (j > 0 && word[i] != word[j])
			j = lmt[j-1];
		if (word[i] == word[j])
			lmt[i] = ++j;
	}

	for (int i = 0, j = 0; i < n; ++i) {
		while (j > 0 && txt[i] != word[j])
			j = lmt[j-1];
		if (txt[i] == word[j])
			if (++j == k)
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
		cout << kmp(word, sentence) << endl;
	}

	return 0;
}
