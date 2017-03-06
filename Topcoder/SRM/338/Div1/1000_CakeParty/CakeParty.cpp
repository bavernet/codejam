#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CakeParty {
public:
	string makeMove(vector <int> pieces) {
		int c = 0, max1 = pieces[0], max2 = 0;
		for (int i = 1; i < pieces.size(); ++i) {
			if (max1 == pieces[i]) {
				if (to_string(i) < to_string(c))
					c = i;
				max2 = max1;
			} else if (max1 < pieces[i]) {
				c = i;
				max2 = max1;
				max1 = pieces[i];
			} else if (max2 < pieces[i]) {
				max2 = pieces[i];
			}
		}

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
