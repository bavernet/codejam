#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string troubleSort(vector<vector<int> > &a) {
	sort(a[0].begin(), a[0].end());
	sort(a[1].begin(), a[1].end());
	int n0 = a[0].size(), n1 = a[1].size();
	for (int i = 0; i < n1; ++i) {
		if (a[0][i] > a[1][i])
			return to_string(i << 1);
		if (i + 1 < n0 && a[1][i] > a[0][i+1])
			return to_string((i << 1) + 1);
	}
	return "OK";
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		int n;
		cin >> n;
		vector<vector<int> > a(2);
		for (int i = 0; i < n; ++i) {
			int ai;
			cin >> ai;
			a[i&1].push_back(ai);
		}
		cout << "Case #" << t << ": " << troubleSort(a) << '\n';
	}
	return 0;
}
