// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14138
// hint: implementation
// level: easy
#include <iostream>
#include <string>

using namespace std;

class CoinFlipsDiv2 {
public:
	int countCoins(string state) {
		int n = state.size();
		int ans = 0;
		for(int i = 1; i + 1 < n; ++i)
			if(state[i-1] != state[i] || state[i+1] != state[i])
				++ans;

		if(n > 1) {
			ans += (state[0] != state[1]);
			ans += (state[n-1] != state[n-2]);
		}

		return ans;
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while(nTests--) {
		string state;
		cin >> state;

		CoinFlipsDiv2 solver;
		cout << solver.countCoins(state) << endl;
	}
	return 0;
}
