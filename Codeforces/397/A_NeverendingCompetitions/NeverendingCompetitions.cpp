// problem: http://codeforces.com/contest/765/problem/A
// hint: implementation
// level: easy
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

string where(const string &home, const vector<pair<string,string> > &itinerary) {
	int cnt = 0;
	for (const auto &p : itinerary)
		if (p.first == home || p.second == home)
			++cnt;
	return (cnt % 2)? "contest": "home";
}

int main(void) {
	cout.sync_with_stdio(false);
	int n;
	cin >> n;

	string home;
	cin >> home;

	string line;
	vector<pair<string,string> > itinerary;
	for (int i = 0; i < n; ++i) {
		cin >> line;
		itinerary.push_back(make_pair(line.substr(0, 3), line.substr(5)));
	}

	cout << where(home, itinerary) << endl;
	return 0;
}
