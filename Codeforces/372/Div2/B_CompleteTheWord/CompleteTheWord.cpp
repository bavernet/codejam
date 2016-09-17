// problem: http://codeforces.com/contest/716/problem/B
// hint: implementation, queue
// level: moderate
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define LEN_ALPHA   26
#define idx(x)      ((x) - 'A')
#define chr(x)      ((x) + 'A')

bool fill(string &word, vector<int> &mask, queue<int> &q) {
	int cur = -1;
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		while (++cur < LEN_ALPHA) {
			if (!mask[cur]) {
				word[i] = chr(cur);
				break;
			}
		}
	}

	for (int i = 0; i < word.size(); ++i)
		if (word[i] == '?')
			word[i] = 'A';

	return true;
}

bool complete(string &word) {
	if (word.size() < LEN_ALPHA)
		return false;

	vector<int> mask(LEN_ALPHA);
	queue<int> q;
	int alpha = 0, n = word.size();

	for (int i = 0; i < LEN_ALPHA; ++i) {
		if (word[i] == '?')
			q.push(i);
		else if (!mask[idx(word[i])]++)
			++alpha;
	}

	if (q.size() + alpha == LEN_ALPHA)
		return fill(word, mask, q);

	for (int i = LEN_ALPHA; i < n; ++i) {
		if (word[i-LEN_ALPHA] == '?')
			q.pop();
		else if (!--mask[idx(word[i-LEN_ALPHA])])
			--alpha;

		if (word[i] == '?')
			q.push(i);
		else if (!mask[idx(word[i])]++)
			++alpha;

		if (q.size() + alpha == LEN_ALPHA)
			return fill(word, mask, q);
	}

	return false;
}

int main(void) {
	string word;
	cin >> word;
	if (complete(word))
		cout << word << endl;
	else
		cout << -1 << endl;
	return 0;
}
