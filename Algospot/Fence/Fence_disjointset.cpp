// problem: https://algospot.com/judge/problem/read/FENCE
// hint: disjointset
// level: moderate
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

inline bool left(map<int,int>::iterator grp, int i) {
	return grp->first - 1 == i;
}

inline bool right(map<int,int>::iterator grp, int i) {
	return grp->first + grp->second == i;
}

int merge(map<int,int> &m, map<int,int>::iterator lg, map<int,int>::iterator rg) {
	lg->second += rg->second + 1;
	m.erase(rg);
	return lg->second;
}

int update(map<int,int> &m, map<int,int>::iterator grp, int i, bool erase) {
	if (erase) {
		m[i] = grp->second + 1;
		m.erase(grp);
		return m[i];
	} else {
		return ++grp->second;
	}
}

int getMaxRectangle(const vector<int> &planks) {
	int n = planks.size(), ans = 0;
	vector<int> ind(n);

	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](const int &a, const int &b) {
		return planks[a] > planks[b];
	});

	map<int,int> m;
	ans = planks[ind[0]];
	for (auto i : ind) {
		auto prev = m.lower_bound(i);
		auto cur = (prev != m.begin())? prev--: prev;
		bool bleft = (cur != m.end())? left(cur, i): false;
		bool bright = (cur != m.begin())? right(prev, i): false;
		if (bleft && bright) {
			ans = max(ans, merge(m, prev, cur) * planks[i]);
		} else if (bleft) {
			ans = max(ans, update(m, cur, i, true) * planks[i]);
		} else if (bright) {
			ans = max(ans, update(m, prev, i, false) * planks[i]);
		} else {
			m[i] = 1;
		}
	}

	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N;
		cin >> N;
		vector<int> planks(N);
		for (int i = 0; i < N; ++i)
			cin >> planks[i];
		cout << getMaxRectangle(planks) << endl;
	}

	return 0;
}
