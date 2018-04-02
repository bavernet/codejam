#include <iostream>
#include <vector>
using namespace std;

static inline double speed(int d, int n, vector<int> &k, vector<int> &s) {
	double time = 0;
	for (int i = 0; i < n; ++i)
		time = max(time, (d - k[i]) * 1.0 / s[i]);
	return d / time;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	cout << fixed;
	cout.precision(10);
	for (int t = 1; t <= nTests; ++t) {
		int d, n;
		cin >> d >> n;
		vector<int> k(n), s(n);
		for (int i = 0; i < n; ++i)
			cin >> k[i] >> s[i];
		cout << "Case #" << t << ": " << speed(d, n, k, s) << endl;
	}
	return 0;
}
