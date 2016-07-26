// problem: https://algospot.com/judge/problem/read/FENCE
// hint: disjointset
// level: moderate
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

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
		auto it = m.lower_bound(i);
		bool updated = false;
		if (it != m.end()) {
			if (it->first - 1 == i) {
				m[i] = it->second + 1;
				m.erase(it);
				it = m.lower_bound(i);
				ans = max(ans, m[i] * planks[i]);
				updated = true;
			}
		}
		if (it != m.begin()) {
			auto nit = it--;
			if (it->first + it->second == i) {
				++it->second;
				if (i == nit->first) {
					it->second += nit->second - 1;
					m.erase(nit);
				}
				ans = max(ans, it->second * planks[i]);
				updated = true;
			}
		}
		if (!updated) {
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
		for (int i = 0; i < N; ++i) {
			cin >> planks[i];
		}

		cout << getMaxRectangle(planks) << endl;
	}

	return 0;
}
