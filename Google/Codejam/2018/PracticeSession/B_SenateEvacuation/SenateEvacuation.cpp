#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <numeric>
#include <cassert>

using namespace std;

vector<string> evacuate(vector<int> &s) {
	vector<string> ans;
	priority_queue<pair<int,char> > pq;
	for (int i = 0, n = s.size(); i < n; ++i)
		pq.push(make_pair(s[i], 'A' + i));

	while (!pq.empty()) {
		pair<int,char> first = pq.top();
		pq.pop();
		pair<int,char> second = pq.top();
		if (first.first - second.first >= 2) {
			if ((first.first -= 2) > 0)
				pq.push(first);
			ans.emplace_back(2, first.second);
		} else if (first.first == second.first && (first.first > 1 || pq.size() != 2)) {
			pq.pop();
			if (--first.first > 0)
				pq.push(first);
			if (--second.first > 0)
				pq.push(second);
			ans.push_back({ first.second, second.second });
		} else {
			if (--first.first > 0)
				pq.push(first);
			ans.emplace_back(1, first.second);
		}
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		int n;
		cin >> n;
		vector<int> senate(n);
		for (int i = 0; i < n; ++i)
			cin >> senate[i];
		cout << "Case #" << t << ": ";
		const vector<string> &ans = evacuate(senate);
		for (const auto &s : ans)
			cout << s << ' ';
		cout << '\n';
	}
	return 0;
}
