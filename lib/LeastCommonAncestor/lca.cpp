#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int lca(const vector<vector<int> > &parent, const vector<int> &depth, int u, int v) {
	if (u == v)
		return u;

	if (depth[u] > depth[v])
		swap(u, v);

	int x = depth[v] - depth[u];

	while (x) {
		int b = x & -x;
		x ^= b;
		v = parent[v][__builtin_ctz(b)];
	}

	if (u == v)
		return u;

	int n = parent.size() - 1;
	for (int i = 32 - __builtin_clz(n); i >= 0; --i) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	u = parent[u][0];
	v = parent[v][0];
	assert(u == v);

	return u;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N, Q;
		cin >> N >> Q;

		vector<vector<int> > parent(N + 1, vector<int>(N + 1));
		vector<int> depth(N + 1);
		depth[1] = 1;
		for (int i = 2; i <= N; ++i) {
			cin >> parent[i][0];
			depth[i] = depth[parent[i][0]] + 1;
		}

		for (int j = 1; (1 << j) < N; ++j) {
			for (int i = 1; i <= N; ++i) {
				if (parent[i][j-1]) {
					parent[i][j] = parent[parent[i][j-1]][j-1];
				}
			}
		}

		for (int i = 1; i <= Q; ++i) {
			int u, v;
			cin >> u >> v;
			cout << lca(parent, depth, u, v) << endl;
		}
	}
	return 0;
}
