// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14173
// hint: implementation, brute force
// level: easy
#include <iostream>
#include <string>

using namespace std;

class EqualSubstrings2 {
public:
	int get(string s) {
		int n = s.size();
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				for(int cnt = 0; i + cnt < j && j + cnt < n; ++cnt) {
					if(s[i + cnt] != s[j + cnt])
						break;
					++ans;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		EqualSubstrings2 solver;
		string s;
		cin >> s;
		cout << solver.get(s) << endl;
	}

	return 0;
}
