#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

#define X_MAX   (20)
#define Y_MAX   (20)
#define R_MAX   (6)
#define H_MAX   (20000)

int r[Y_MAX+1];
double dp[H_MAX+1][X_MAX+1][R_MAX+1];

static inline double prob(int h, int x, int y) {
	if (h <= 0) return 1.0;
	if (x == 0) return 0.0;
	double &p = dp[h][x][r[y]];
	if (!isnan(p))
		return p;
	p = 0.0;
	for (int i = y; i > 0; --i) {
		double sp = prob(h - i, x - 1, y);
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
	return prob(h, x, y);
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
	memset(dp, 0xFF, sizeof(dp));
	r[4] = 0, r[6] = 1, r[8] = 2, r[10] = 3, r[12] = 4, r[20] = 5;
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
