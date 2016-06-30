#include <iostream>
#include <vector>

using namespace std;

#define MAX_N   (2000)

int cache[MAX_N+1][MAX_N+1];
int snakes[MAX_N+1];

int getMaxCapacity(int start, int end) {
	if (start >= end)
		return 0;

	int &ans = cache[start][end];
	if (ans >= 0)
		return ans;

	ans = getMaxCapacity(start, end - 1);
	int last = snakes[end];
	for (int i = start; i < end; ++i) {
		int cur = snakes[i] * last;
		if (cur > 0)
			continue;

		int before = getMaxCapacity(start, i - 1);
		int after = getMaxCapacity(i + 1, end - 1);
		ans = max(ans, before - cur + after);
	}

	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N, gender;
		cin >> N;

		memset(cache, 0xFF, sizeof(cache));
		for (int i = 1; i <= N; ++i) {
			cin >> snakes[i];
		}
		for (int i = 1; i <= N; ++i) {
			cin >> gender;
			if (gender) {
				snakes[i] *= -1;
			}
		}

		cout << getMaxCapacity(1, N) << endl;
	}

	return 0;
}
