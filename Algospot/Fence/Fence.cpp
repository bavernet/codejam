// problem: https://algospot.com/judge/problem/read/FENCE
// hint: divide and conquer
// level: easy
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void getRectangles(map<int,int> &ans, const vector<int> &planks, int s, int e) {
	int unit = (s > e)? -1: 1;
	int prevH = planks[s];
	int d = 1;
	for (int i = s + unit; i != e; i += unit, ++d) {
		if (prevH > planks[i]) {
			ans[prevH] = d;
			prevH = planks[i];
		}
	}
	ans[prevH] = d;
}

int getMax(map<int,int> &src, map<int,int> &tgt) {
	int ans = 0;
	for (auto p : src) {
		auto it = tgt.lower_bound(p.first);
		if (it == tgt.end())
			continue;

		int width = p.second + it->second;
		ans = max(ans, p.first * width);
	}
	return ans;
}

int getMaxRectangle(const vector<int> &planks, int s, int e) {
	if (e - s == 0)
		return 0;

	if (e - s == 1)
		return planks[s];

	int m = (s + e) / 2;
	int left = getMaxRectangle(planks, s, m);
	int right = getMaxRectangle(planks, m, e);

	map<int,int> leftRects, rightRects;
	if (m > 0)  getRectangles(leftRects, planks, m - 1, -1);
	if (m < e)  getRectangles(rightRects, planks, m, e);

	int ans = max(left, right);
	int mid = max(getMax(leftRects, rightRects), getMax(rightRects, leftRects));
	return max(ans, mid);
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
