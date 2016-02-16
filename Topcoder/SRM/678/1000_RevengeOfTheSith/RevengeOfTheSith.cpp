// problem: https://community.topcoder.com/stat?c=problem_statement&pm=13191&rd=16648
// hint: 
// level: moderate
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class RevengeOfTheSith {
private:
	int cost(int height, int space, int D) {
		int lh = max(0, height / space - D);
		int hh = max(0, height / space + 1 - D);
		int hc = height % space;
		int lc = space - hc;
		return lh * lh * lc + hh * hh * hc;
	}
public:
	int move(vector<int> steps, int T, int D) {
		int N = steps.size();
		vector<int> height(N);
		height[0] = steps[0];
		for(int i = 1; i < height.size(); ++i) {
			height[i] = height[i-1] + steps[i];
		}

		vector<vector<int> > dp(N + 1, vector<int>(N + 1));
		for(int t = 0; t <= T; ++t) {
			for(int r = 1; r <= N; ++r) {
				for(int l = 0; l < r; ++l) {
					:q
				}
			}
		}
		dp[0][T] = 0;
		for(int r = 1; r <= N; ++r) {
			for(int t = 0; t <= T; ++t) {
				for(int l = 0; l < r; ++l) {
					int mov = r - l - 1;
					if(mov <= t) {
						dp[r][t-mov] = min(dp[r][t-mov],
							dp[l][t] + cost(height[r] - height[l], r - l, D));
					}
				}
			}
		}

		int answer = INT_MAX;
		for(int t = 0; t <= T; ++t) {
			answer = min(answer, dp[N][t]);
		}
		return answer;
	}
};

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int N, T, D;
		cin >> N;

		vector<int> steps(N);
		for(int i = 0; i < N; ++i) {
			cin >> steps[i];
		}
		cin >> T >> D;

		RevengeOfTheSith solver;
		cout << solver.move(steps, T, D) << endl;
	}

	return 0;
}
