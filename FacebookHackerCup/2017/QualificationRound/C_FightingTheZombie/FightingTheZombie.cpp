#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

double prob(int h, int x, int y, map<int,map<int,double> > &dp) {
	if (h <= 0) return 1.0;
	if (x == 0) return 0.0;
	if (dp[x].find(h) != dp[x].end())
		return dp[x][h];
	double &p = dp[x][h];
	for (int i = y; i > 0; --i) {
		double sp = prob(h - i, x - 1, y, dp);
		if (!sp)
			break;
		p += 1.0 / y * sp;
	}
	return p;
}

double prob(int h, string &spell) {
	stringstream sin(spell);
	int x, y, z = 0;
	char c;
	sin >> x >> c >> y >> z;
	h -= z;
	map<int,map<int,double> > dp;
	return prob(h, x, y, dp);
}

double win(int h, vector<string> &spells) {
	double maxProb = -1.0;
	for (auto &s : spells) {
		maxProb = max(maxProb, prob(h, s));
		if (maxProb == 1.0)
			break;
	}
	return maxProb;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	cout << fixed;
	cout.precision(6);
	for (int t = 1; t <= nTests; ++t) {
		int h, s;
		cin >> h >> s;
		vector<string> spells(s);
		for (int i = 0; i < s; ++i)
			cin >> spells[i];
		cout << "Case #" << t << ": " << win(h, spells) << endl;
	}
	return 0;
}
