#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

#define MAX_N   (100000)

int parent[MAX_N+1];
int depth[MAX_N+1];
int cost[MAX_N+1];

inline int getCommonAncestor(int a, int b) {
	while (depth[a] > depth[b]) a = parent[a];
	while (depth[b] > depth[a]) b = parent[b];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

void dijkstra(vector<map<int,int> > &g, vector<int> &d, int s) {
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	vector<bool> visited(d.size());

	d[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		pair<int,int> p = pq.top();
		pq.pop();

		int u = p.second;
		if (visited[u])
			continue;

		visited[u] = true;
		for (const auto &adj : g[u]) {
			int v = adj.first;
			int c = adj.second;
			if (d[v] > d[u] + c) {
				d[v] = d[u] + c;
				pq.push(make_pair(d[v], v));
			}
		}
	}
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N, Q;
		cin >> N >> Q;

		vector<map<int,int> > g(N + 1);
		set<int> leaf;
		cost[1] = 0;
		depth[1] = 1;
		for (int i = 2; i <= N; ++i) {
			int P, C;
			cin >> P >> C;
			g[P][i] = g[i][P] = C;
			parent[i] = P;
			cost[i] = cost[P] + C;
			depth[i] = depth[P] + 1;
			leaf.erase(P);
			leaf.insert(i);
		}

		for (const int &v : leaf) {
			int nc;
			cin >> nc;
			if (g[v][1])
				nc = min(g[v][1], nc);
			g[1][v] = g[v][1] = nc;
		}

		vector<int> d(N + 1, INT_MAX);
		dijkstra(g, d, 1);

		long long before = 0, after = 0;
		for (int i = 0; i < Q; ++i) {
			int a, b;
			cin >> a >> b;

			int ancestor = getCommonAncestor(a, b);
			int dist = cost[a] + cost[b] - cost[ancestor] * 2;
			before += dist;
			after += min(dist, d[a] + d[b]);
		}

		cout << before << " " << after << endl;
	}

	return 0;
}
