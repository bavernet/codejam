// problem: https://algospot.com/judge/problem/read/ARCTIC
// hint: graph, priority_queue
// level: moderate
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<double,int> edge;
typedef priority_queue<edge,vector<edge>,greater<edge> > min_heap;

double dist(const pair<double,double> &a, const pair<double,double> &b) {
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x*x + y*y);
}

double minPower(const vector<pair<double,double> > &xy) {
	int n = xy.size();
	vector<map<int,double> > g(n);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			g[i][j] = g[j][i] = dist(xy[i], xy[j]);

	double ans = 0.0;
	vector<bool> tree(n);
	min_heap pq;
	pq.push(make_pair(0, 0));
	for (int i = 0; i < n; ++i) {
		while (!pq.empty()) {
			edge e = pq.top();
			pq.pop();
			double d = e.first;
			int u = e.second;
			if (!tree[u]) {
				tree[u] = true;
				ans = max(ans, d);
				for (auto &p : g[u])
					pq.push(make_pair(p.second, p.first));
				break;
			}
		}
	}
	return ans;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<pair<double,double> > xy(n);
		for (int i = 0; i < n; ++i) {
			cin >> xy[i].first >> xy[i].second;
		}

		cout << fixed;
		cout.precision(2);
		cout << minPower(xy) << endl;
	}
	return 0;
}
