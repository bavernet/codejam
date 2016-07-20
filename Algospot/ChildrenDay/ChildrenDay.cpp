// problem: https://algospot.com/judge/problem/read/CHILDRENDAY
// hint: tree, graph, bfs
// level: hard
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

string countToys(string &d, int m, int n) {
	queue<pair<int,string> > q;
	vector<bool> visited(n);

	sort(d.begin(), d.end());
	for (const char c : d)
		q.push(make_pair(0, string(1, c)));

	while (!q.empty()) {
		pair<int,string> p = q.front();
		q.pop();

		int num = (p.first * 10) + (p.second.back() - '0');
		int rest = num % n;
		if (rest == m && (p.second.size() > 5 || stoi(p.second) >= n))
			return p.second;

		if (visited[rest])
			continue;

		visited[rest] = true;
		for (const char c : d)
			q.push(make_pair(rest, p.second + c));
	}

	return "IMPOSSIBLE";
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string d;
		int m, n;
		cin >> d >> n >> m;
		cout << countToys(d, m, n) << endl;
	}

	return 0;
}
