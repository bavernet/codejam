#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX_N   (100000)

int parent[MAX_N+1];
int depth[MAX_N+1];
int cost[MAX_N+1];
int cache[MAX_N+1];

inline int getCommonAncestor(int a, int b) {
	while (depth[a] > depth[b]) a = parent[a];
	while (depth[b] > depth[a]) b = parent[b];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int getCost(map<int,int> &leaf, int v) {
	int &c = cache[v];
	if (c > 0)
		return c;

	c = cost[v];
	for (const auto &p : leaf) {
		if (c <= p.second)
			continue;
		int ancestor = getCommonAncestor(v, p.first);
		int dist = cost[v] + cost[p.first] - cost[ancestor] * 2;
		c = min(c, dist + p.second);
	}
	return c;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N, Q;
		cin >> N >> Q;

		map<int,int> leaf;
		cost[1] = 0;
		depth[1] = 1;
		for (int i = 1; i < N; ++i) {
			int P, C;
			cin >> P >> C;
			parent[i+1] = P;
			cost[i+1] = cost[P] + C;
			depth[i+1] = depth[P] + 1;
			leaf.erase(P);
			leaf[i + 1] = 0;
		}

		for (auto &p : leaf) {
			cin >> p.second;
		}

		memset(cache, 0, sizeof(int) * (N + 1));
		long long before = 0, after = 0;
		for (int i = 0; i < Q; ++i) {
			int a, b;
			cin >> a >> b;

			int ancestor = getCommonAncestor(a, b);
			int dist = cost[a] + cost[b] - cost[ancestor] * 2;
			before += dist;

			int costA = getCost(leaf, a);
			int costB = getCost(leaf, b);
			after += min(dist, costA + costB);
		}

		cout << before << " " << after << endl;
	}

	return 0;
}
