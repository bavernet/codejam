// problem: http://codeforces.com/contest/761/problem/E
// hint: greedy, tree, math
// level: moderate
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

enum { LEFT = 0, UP, RIGHT, DOWN, N_DIR };
enum { X = 0, Y, XY };
long long unit[N_DIR][XY] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

void fill(const vector<vector<int> > &tree, int node, unsigned int len, int dir,
		  vector<pair<long long, long long> > &pt) {
	const pair<long long, long long> &cur = pt[node-1];
	for (auto child: tree[node]) {
		pt[child-1].first  = cur.first  + len * unit[dir][X];
		pt[child-1].second = cur.second + len * unit[dir][Y];
		fill(tree, child, len >> 1, (dir + N_DIR - 1) % N_DIR, pt);
		dir = (dir + 1) % N_DIR;
	}
}

bool draw(vector<vector<int> > &tree, vector<pair<long long,long long> > &pt) {
	vector<int> depth(tree.size());
	stack<int> st;
	int maxDepth = 0;
	st.push(1);
	depth[1] = 0;
	if (tree[1].size() > 4)
		return false;

	while (!st.empty()) {
		int v = st.top();
		int d = depth[v];
		st.pop();
		for (auto child : tree[v]) {
			depth[child] = d + 1;
			maxDepth = max(maxDepth, depth[child]);
			if (tree[child].size() > 4)
				return false;
			tree[child].erase(find(tree[child].begin(), tree[child].end(), v));
			st.push(child);
		}
	}

	pt[0] = make_pair(0, 0);
	fill(tree, 1, 1U << maxDepth, UP, pt);
	return true;
}

int main(void) {
	cout.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > tree(n+1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	vector<pair<long long,long long> > pt(n);
	if (draw(tree, pt)) {
		cout << "YES" << endl;
		for (auto p : pt)
			cout << p.first << ' ' << p.second << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
