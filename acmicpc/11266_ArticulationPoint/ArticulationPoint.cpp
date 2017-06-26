// problem: https://www.acmicpc.net/problem/11266
// hint: articulation-point, dfs
// level: moderate
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, int p, int &order, vector<int> &num, vector<int> &low, vector<int> &ap, const vector<vector<int> > &g) {
	low[u] = num[u] = ++order;
	bool isAP = false, isRoot = (p < 0);
	int nChild = 0;
	for (auto v : g[u]) {
		if (v == p)
			continue;
		if (!num[v]) {
			++nChild;
			dfs(v, u, order, num, low, ap, g);
			if (num[u] <= low[v])
				isAP = true;
		}
		low[u] = min(low[u], low[v]);
	}
	if ((isRoot && nChild >= 2) || (!isRoot && isAP))
		ap.push_back(u + 1);
}

vector<int> getAP(const vector<vector<int> > &g) {
	int n = g.size();
	vector<int> ap;
	vector<int> num(n), low(n);
	int order = 0;
	for (int i = 0; i < n; ++i)
		if (!num[i])
			dfs(i, -1, order, num, low, ap, g);
	sort(ap.begin(), ap.end());
	return ap;
}

int main(void) {
	cout.sync_with_stdio(false);
	int v, e;
	cin >> v >> e;
	vector<vector<int> > g(v);
	for (int i = 0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	const vector<int> &ap = getAP(g);
	cout << ap.size() << '\n';
	for (auto &p : ap)
		cout << p << ' ';
	cout << '\n';
	return 0;
}
