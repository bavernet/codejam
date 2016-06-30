#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool kmp(const vector<int> &doc, const vector<int> &word) {
	vector<int> fail(word.size(), 0);

	for (int i = 1; i < word.size(); ++i) {
		int j = fail[i-1];
		while (j > 0 && word[i] != word[j])
			j = fail[j-1];
		if (word[i] == word[j])
			fail[i] = j + 1;
	}

	int i, j;
	for (i = 0, j = 0; i < doc.size(); ++i, ++j) {
		if (j == word.size())
			return true;

		if (j > 0 && doc[i] != word[j])
			j = fail[j-1];

		if (doc[i] != word[j])
			j = -1;
	}

	return j == word.size();
}

void reverse(vector<int> &p) {
	reverse(p.begin(), p.end());
	int n = p.size();
	int lastDir = (p[0] > 0)? -1: 1;
	for (int i = 0; i + 1 < n; ++i) {
		int dir = (p[i+1] > 0)? -1: 1;
		p[i] = abs(p[i]) * dir;
	}
	p[n-1] = abs(p[n-1]) * lastDir;
}

bool equals(vector<int> &src, vector<int> &tgt) {
	src.insert(src.end(), src.begin(), src.end());

	if (kmp(src, tgt))
		return true;

	reverse(tgt);
	return kmp(src, tgt);
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N;
		cin >> N;

		vector<int> src(N), tgt(N);
		for (int i = 0; i < N; ++i)
			cin >> src[i];
		for (int i = 0; i < N; ++i)
			cin >> tgt[i];

		cout << equals(src, tgt) << endl;
	}

	return 0;
}
