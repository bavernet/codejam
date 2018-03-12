#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct strcomp {
	bool operator ()(const int &a, const int &b) {
		return to_string(a) < to_string(b);
	}
};

class CakeParty {
public:
	string makeMove(vector<int> pieces) {
		int n = pieces.size();
		map<int,set<int,strcomp> > m;
		for (int i = 0; i < n; ++i)
			m[pieces[i]].insert(i);

		int x = 0;
		for (auto sz : pieces)
			x ^= sz;

		auto it = m.rbegin();
		int cake = *it->second.begin();
		int max1 = it->first;
		int target = x ^ max1;
		if (!x || max1 < target)
			return "CAKE " + to_string(cake) + " PIECES 1";

		set<int,strcomp> s;
		s.insert(max1 - target);
		cout << "ans: " << (max1 - target) << endl;
		int max2 = (it->second.size() > 1)? max1: (++it)->first;
		for (int i = 1, e = target; i <= e; ++i) {
			int nx = target ^ i;
			int nt = nx ^ max2;
			if (max2 <= nt) {
				s.insert(max1 - i);
				cout << "i: " << i << endl;
			}
		}
		return "CAKE " + to_string(cake) + " PIECES " + to_string(*s.begin());

#if 0
		int x = 0;
		for (auto sz : pieces)
			x ^= sz;
		if (!x)
			return "CAKE " + to_string(c) + " PIECES 1";
		int p = (x ^ max1 ^ max2) != 0;
		if (max1 < x)
			x -= 1 << (31 - __builtin_clz(x));
		p += max1 - max2;
		//cout << "x: " << x << ", p: " << p << ", max1: " << max1 << ", max2: " << max2 << endl;
		for (int i = p + 1; i <= x; ++i)
			if (to_string(i) < to_string(p))
				p = i;
		return "CAKE " + to_string(c) + " PIECES " + to_string(p);
#endif
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<int> pieces(n);
		for (int i = 0; i < n; ++i)
			cin >> pieces[i];

		CakeParty sol;
		cout << sol.makeMove(pieces) << endl;
	}
	return 0;
}
