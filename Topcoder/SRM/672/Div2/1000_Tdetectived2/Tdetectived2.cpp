// problem: http://community.topcoder.com/stat?c=problem_statement&pm=14076&rd=16552
// hint: graph, dfs, dp
// level: moderate
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <climits>

using namespace std;

class Tdetectived2 {
private:
	char getMax(const string &ev, int state) {
		char maxVal = -1;
		for(int i = 1; i < ev.size(); ++i) {
			if(!((state >> i) & 0x01) && maxVal < ev[i]) {
				maxVal = ev[i];
			}
		}
		return maxVal;
	}

	map<int,vector<int> > graph(const vector<string> &s) {
		map<int,vector<int> > g;
		map<int,bool> visit;
		stack<int> st;

		st.push(1 << 0);
		while(!st.empty()) {
			int state = st.top();
			st.pop();

			if(visit[state])
				continue;
			visit[state] = true;

			char maxVal = -1;
			for(int i = 0; i < s.size(); ++i) {
				if((state >> i) & 0x01) {
					const string &ev = s[i];
					maxVal = max(maxVal, getMax(ev, state));
				}
			}

			if(maxVal < 0)
				continue;

			for(int i = 0; i < s.size(); ++i) {
				if((state >> i) & 0x01) {
					const string &ev = s[i];
					for(int j = 1; j < ev.size(); ++j) {
						if(!((state >> j) & 0x01) && ev[j] == maxVal) {
							int nextState = state | (1 << j);
							st.push(nextState);
							g[state].push_back(nextState);
						}
					}
				}
			}
		}

		return g;
	}
public:
	int reveal(vector<string> s) {
		map<int,vector<int> > g = graph(s);
		vector<int> ans(s.size(), INT_MAX);
		map<int,int> visit;
		queue<pair<int,int> > q;
		q.push(make_pair(0, 1 << 0));
		visit[0] = -1;
		while(!q.empty()) {
			pair<int,int> p = q.front();
			int prev = p.first;
			int cur = p.second;
			int selected = __builtin_ctz(prev ^ cur);
			q.pop();

			if(visit[cur] > 0)
				continue;
			visit[cur] = visit[prev] + 1;
			ans[selected] = min(ans[selected], visit[cur]);

			const vector<int> &vs = g[cur];
			for(int next : vs) {
				q.push(make_pair(cur, next));
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
