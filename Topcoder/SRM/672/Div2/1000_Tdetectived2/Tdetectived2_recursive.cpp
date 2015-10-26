#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

unsigned int ans[20];

class Tdetectived2 {
public:
	int reveal(vector<string> s) {
		int answer = 0;
		string level(s.size(), '0');
		memset(ans, 0xFF, sizeof(ans));
		reveal(s, level, 0, 0);
		cout << "answer: ";
		for(int i = 1; i < s.size(); ++i) {
			answer += i * ans[i];
			cout << ans[i] << " ";
		}
		cout << endl;
		return answer;
	}

	void reveal(vector <string> &s, string level, int idx, int round) {
		static map<string,int> cache;

		level[idx] = '0' - 1;
		ans[idx] = min(ans[idx], (unsigned int)round);
		if(cache[level] && cache[level] < round)
			return ;
		cache[level] = round;

		string &ev = s[idx];
		for(int i = 1; i < ev.size(); ++i) {
			if(level[i] >= '0') {
				level[i] = max(level[i], ev[i]);
			}
		}
		char m = *max_element(level.begin(), level.end());
		if(m >= '0') {
			for(int i = 1; i < level.size(); ++i) {
				if(level[i] == m) {
					reveal(s, level, i, round + 1);
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
