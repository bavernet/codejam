// problem: https://algospot.com/judge/problem/read/FENCE
// hint: divide and conquer
// level: easy
#include <iostream>
#include <vector>

using namespace std;

int getMaxRectangle(const vector<int> &planks, int s, int e) {
	if (e - s == 0)
		return 0;

	if (e - s == 1)
		return planks[s];

	int m = (s + e) / 2;
	int left = getMaxRectangle(planks, s, m);
	int right = getMaxRectangle(planks, m, e);
	int ans = max(left, right);

	int lo = m;
	int hi = m + 1;
	int minH = planks[m];
	while (s < lo || hi < e) {
		if (s < lo && (hi == e || planks[lo-1] > planks[hi])) {
			--lo;
			minH = min(minH, planks[lo]);
		} else {
			minH = min(minH, planks[hi]);
			++hi;
		}
		ans = max(ans, minH * (hi - lo));
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

		cout << getMaxRectangle(planks, 0, N) << endl;
	}

	return 0;
}
