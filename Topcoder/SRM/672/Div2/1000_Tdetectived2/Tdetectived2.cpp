// problem: http://community.topcoder.com/stat?c=problem_statement&pm=14076&rd=16552
// hint: graph, bfs, dp
// level: moderate
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <climits>

#define VISITED(state, i) ((state >> i) & 0x01)

using namespace std;

class Tdetectived2 {
private:
	char getMax(const vector<string> &s, int state) {
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
		return maxVal;
	}
public:
	int reveal(vector<string> s) {
		vector<int> ans(s.size(), INT_MAX);
		map<int,bool> visit;
		queue<int> q;
		q.push(1 << 0);
		ans[0] = 0;
		while(!q.empty()) {
			int state = q.front();
			q.pop();

			if(visit[state])
				continue;
			visit[state] = true;

			char maxVal = getMax(s, state);
			if(maxVal < 0)
				continue;

			for(int i = 0; i < s.size(); ++i) {
				if(VISITED(state, i)) {
					const string &ev = s[i];
					int dist = __builtin_popcount(state);
					for(int j = 1; j < ev.size(); ++j) {
						if(!VISITED(state, j) && ev[j] == maxVal) {
							int nextState = state | (1 << j);
							ans[j] = min(ans[j], dist);
							q.push(nextState);
						}
					}
				}
			}
		}
		int answer = 0;
		for(int i = 1; i < ans.size(); ++i) {
			answer += i * ans[i];
		}
		return answer;
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
