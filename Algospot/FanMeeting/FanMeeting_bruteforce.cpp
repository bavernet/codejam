// problem: https://algospot.com/judge/problem/read/FANMEETING
// hint: brute-force
// level: moderate
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#define L_MAX   (200000)

bitset<L_MAX> impossible;

int solve(const string &star, const string &fan) {
	int n = fan.size() - star.size() + 1;
	int ans = n;

	vector<int> manStar, manFan;
	for (int i = 0; i < star.size(); ++i)
		if (star[i] == 'M')
			manStar.push_back(i);
	for (int i = 0; i < fan.size(); ++i)
		if (fan[i] == 'M')
			manFan.push_back(i);

	impossible.reset();
	for (int sidx : manStar) {
		for (auto it = lower_bound(manFan.begin(), manFan.end(), sidx);
			 it != manFan.end(); ++it) {
			int fidx = *it;
			int idx = fidx - sidx;
			if (idx >= n)
				break;

			if (!impossible[idx]) {
				impossible[idx] = true;
				--ans;
			}
		}
	}

	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string star;
		string fan;
		cin >> star;
		cin >> fan;
		cout << solve(star, fan) << endl;
	}

	return 0;
}
