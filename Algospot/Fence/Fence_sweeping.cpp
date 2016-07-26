// problem: https://algospot.com/judge/problem/read/FENCE
// hint: sweeping, stack
// level: moderate
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int getMaxRectangle(const vector<int> &planks) {
	stack<int> s;
	int ans = 0, n = planks.size();

	s.push(0);
	for (int i = 1; i < n; ++i) {
		while (planks[s.top()] > planks[i]) {
			int j = s.top();
			s.pop();
			ans = max(ans, (i - s.top() - 1) * planks[j]);
		}

		if (planks[s.top()] <= planks[i])
			s.push(i);
	}

	while (s.size() > 1) {
		int j = s.top();
		s.pop();
		ans = max(ans, (n - s.top() - 1) * planks[j]);
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

		vector<int> planks(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> planks[i];
		}

		cout << getMaxRectangle(planks) << endl;
	}

	return 0;
}
