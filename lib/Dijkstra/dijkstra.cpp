#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N;

typedef pair<int,int> dist;
typedef priority_queue<dist, vector<dist>, greater<dist> > min_heap;

void dijkstra(vector<map<int,int> > &g, int s) {
	min_heap pq;
	vector<int> d(N + 1, INT_MAX);
	vector<int> visited(N + 1);

	d[1] = 0;
	pq.push(make_pair(0, 1));
	while(!pq.empty()) {
		pair<int,int> p = pq.top();
		pq.pop();

		int u = p.second;
		if (visited[u])
			continue;

		visited[u] = true;
		for (auto next : g[u]) {
			int v = next.first;
			int nextCost = next.second;
			if (d[v] > d[u] + nextCost) {
				d[v] = d[u] + nextCost;
				pq.push(make_pair(d[v], v));
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int E;
		cin >> N >> E;

		vector<map<int,int> > g(N + 1);
		for (int i = 0; i < E; ++i) {
			int u, v, cost;
			cin >> u >> v >> cost;
			g[u][v] = cost;
		}

		dijkstra(g, 1);
	}

	return 0;
}
