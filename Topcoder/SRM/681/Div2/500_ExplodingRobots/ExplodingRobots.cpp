// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14137
// hint: greedy
// level: easy
#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

class ExplodingRobots {
public:
	string canExplode(int x1, int y1, int x2, int y2, string instructions) {
		map<char,int> cnt;
		for(char c : instructions) {
			++cnt[c];
		}
		if(abs(x1 - x2) <= cnt['L'] + cnt['R'] && abs(y1 - y2) <= cnt['U'] + cnt['D'])
			return "Explosion";
		return "Safe";
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		int x1, y1, x2, y2;
		string inst;

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> inst;

		ExplodingRobots solver;
		cout << solver.canExplode(x1, y1, x2, y2, inst) << endl;
	}
	return 0;
}
