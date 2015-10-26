// problem: http://community.topcoder.com/stat?c=problem_statement&pm=14076&rd=16552
// hint: graph, dfs, dp, recursive
// level: moderate
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>

#define VISITED(s,i)    (((s) >> (i)) & 0x01)
#define MAX_N           (20)

using namespace std;

class Tdetectived2 {
private:
	int ans[MAX_N];
	map<int,bool> cache;

public:
	int reveal(vector<string> s) {
		int answer = 0;
		fill(ans, ans + s.size(), INT_MAX);
		cache.clear();
		reveal(s, 1 << 0, 0, 0);
		for(int i = 1; i < s.size(); ++i) {
			answer += i * ans[i];
		}
		return answer;
	}

	void reveal(const vector <string> &s, int state, int idx, int round) {
		if(cache[state])
			return ;
		cache[state] = true;
		ans[idx] = min(ans[idx], round);

		char maxVal = -1;
		for(int i = 0; i < s.size(); ++i) {
			if(VISITED(state, i)) {
				const string &ev = s[i];
				for(int j = 1; j < ev.size(); ++j) {
					if(!VISITED(state, j) && maxVal < ev[j]) {
						maxVal = ev[j];
					}
				}
			}
		}
		if(maxVal < 0)
			return ;

		for(int i = 0; i < s.size(); ++i) {
			if(VISITED(state, i)) {
				const string &ev = s[i];
				for(int j = 1; j < ev.size(); ++j) {
					if(!VISITED(state, j) && maxVal == ev[j]) {
						reveal(s, state | (1 << j), j, round + 1);
					}
				}
			}
		}
	}
};

int main(void) {
	int nTests = 0;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;
		vector<string> s(n, "");
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		Tdetectived2 solver;
		cout << solver.reveal(s) << endl;
	}

	return 0;
}
