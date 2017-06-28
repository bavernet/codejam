// problem: https://www.acmicpc.net/problem/2887
// hint: dsu, mst
// level: moderate
#include <iostream>
#include <tuple>
#include <numeric>
#include <vector>
#include <algorithm>
#include <type_traits>
using namespace std;

typedef tuple<int,int,int> point;
typedef tuple<int,int,int> edge;

template <int N>
void addEdges(vector<int> &r, vector<edge> &edges, const vector<point> &planets,
			  integral_constant<int,N>) {
	int n = planets.size();
	sort(r.begin(), r.end(), [&](auto &a, auto &b) {
		int ax = get<N>(planets[a]);
		int bx = get<N>(planets[b]);
		return ax < bx;
	});
	for (int i = 1; i < n; ++i) {
		int ax = get<N>(planets[r[i-1]]);
		int bx = get<N>(planets[r[i]]);
		edges.emplace_back(bx - ax, r[i-1], r[i]);
	}
}

int root(int i, vector<int> &parent) {
	if (i == parent[i])
		return i;
	return parent[i] = root(parent[i], parent);
}

long long cost(const vector<point> &planets) {
	int n = planets.size();
	vector<edge> edges;
	vector<int> r(n);
	iota(r.begin(), r.end(), 0);
	addEdges(r, edges, planets, integral_constant<int,0>());
	addEdges(r, edges, planets, integral_constant<int,1>());
	addEdges(r, edges, planets, integral_constant<int,2>());

	vector<int> parent(n);
	vector<long long> cost(n);
	iota(parent.begin(), parent.end(), 0);
	sort(edges.begin(), edges.end());
	for (auto &e : edges) {
		int u, v, c;
		tie(c, u, v) = e;
		int ru = root(u, parent);
		int rv = root(v, parent);
		if (ru != rv) {
			parent[ru] = rv;
			cost[rv] += cost[ru] + c;
		}
	}
	return cost[root(0, parent)];
}

int main(void) {
	cout.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<point> planets;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		planets.emplace_back(x, y, z);
	}
	cout << cost(planets) << endl;
	return 0;
}
