// problem: https://algospot.com/judge/problem/read/CLOCKSYNC
// hint: exhaustive search, recursive
// level: medium
#include <iostream>
#include <vector>

#define N_CLOCKS    (16)
#define N_BUTTONS   (10)
#define INF         (123456789)

using namespace std;

vector<int> button[N_BUTTONS] = {
	{ 0,  1,  2 },
	{ 3,  7,  9, 11 },
	{ 4, 10, 14, 15 },
	{ 0,  4,  5,  6,  7 },
	{ 6,  7,  8, 10, 12 },
	{ 0,  2, 14, 15 },
	{ 3, 14, 15 },
	{ 4,  5,  7, 14, 15 },
	{ 1,  2,  3,  4,  5 },
	{ 3,  4,  5,  9, 13 }
};

int sync(int bid, vector<int> &clocks) {
	if(bid == N_BUTTONS) {
		for(int c : clocks)
			if(c)
				return INF;
		return 0;
	}

	int ans = INF;
	for(int i = 0; i < 4; ++i) {
		ans = min(ans, i + sync(bid + 1, clocks));
		for(int c : button[bid])
			clocks[c] = (clocks[c] + 1) & 0x03;
	}

	return ans;
}

int sync(vector<int> &clocks) {
	int answer = sync(0, clocks);
	return (answer < INF)? answer: -1;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while(nTests--) {
		vector<int> clocks(N_CLOCKS);
		for(int i = 0; i < N_CLOCKS; ++i) {
			cin >> clocks[i];
			clocks[i] = (clocks[i] / 3) % 4;
		}

		cout << sync(clocks) << endl;
	}

	return 0;
}
