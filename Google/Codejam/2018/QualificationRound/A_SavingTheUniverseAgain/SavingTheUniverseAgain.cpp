#include <iostream>
#include <string>
#include <queue>
using namespace std;

string hack(unsigned int d, string &p) {
	priority_queue<unsigned int> pq;
	unsigned int c = 1, total = 0;
	for (auto op : p) {
		if (op == 'C') {
			c <<= 1;
		} else {
			pq.push(c);
			total += c;
		}
	}
	int cnt = 0;
	while (total > d && !pq.empty()) {
		unsigned int max = pq.top();
		pq.pop();
		if (max == 1)
			return "IMPOSSIBLE";
		max >>= 1;
		pq.push(max);
		total -= max;
		++cnt;
	}
	return to_string(cnt);
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		unsigned int d;
		cin >> d;
		string p;
		cin >> p;
		cout << "Case #" << t << ": " << hack(d, p) << '\n';
	}
	return 0;
}
