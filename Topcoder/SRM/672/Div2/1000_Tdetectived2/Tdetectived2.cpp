#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <utility>

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
		stack<pair<int,int> > st;

		st.push(make_pair(0, 1 << 0));
		while(!st.empty()) {
			pair<int,int> p = st.top();
			int selected = p.first;
			int state = p.second;
			st.pop();

			if(visit[state])
				continue;
			visit[state] = true;

			const string &ev = s[selected];
			char maxVal = getMax(ev, state);
			if(maxVal < 0)
				continue;

			for(int i = 1; i < ev.size(); ++i) {
				if(ev[i] == maxVal) {
					int nextState = state | (1 << i);
					st.push(make_pair(i, nextState));
					g[state].push_back(nextState);
				}
			}
		}

		return g;
	}
public:
	int reveal(vector<string> s) {
		map<int,vector<int> > g = graph(s);
		vector<int> ans(s.size(), INT_MAX);
		map<int,bool> visit;
		queue<pair<int,int> > q;
		q.push(make_pair(0, 1 << 0));
		while(!q.empty()) {
			pair<int,int> p = q.front();
			int selected = p.first;
			int state = p.second;
			q.pop();

			if(visit[state])
				continue;
			visit[state];

			const vector<int> &v = g[state];
		}

		int answer = 0;
		for(int i = 1; i < ans.size(); ++i) {
			answer += i * ans[i];
		}
		return answer;

#if 0
		vector<int> answer(s.size(), INT_MAX);
		set<int> visitList;
		int n = s.size();
		visitList.insert(0);
		answer[0] = 0;
		s[0][0] = -1;
		while(visitList.size() < n) {
			char maxVal = '0' - 1;
			for(int v : visitList) {
				string &ev = s[v];
				for(int i = 1; i < ev.size(); ++i) {
					maxVal = max(maxVal, ev[i]);
				}
			}

			set<int> maxList;
			for(int v : visitList) {
				string &ev = s[v];
				for(int i = 1; i < ev.size(); ++i) {
					if(ev[i] >= '0' && ev[i] == maxVal) {
						maxList.insert(i);
						answer[i] = min(answer[i], answer[v]+1);
						s[v][i] = s[i][v] = '0' - 1;
					}
				}
			}

			visitList.insert(maxList.begin(), maxList.end());
		}

		int ans = 0;
		for(int i = 1; i < answer.size(); ++i) {
			ans += i * answer[i];
		}

		return answer;
#endif
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
