// problem: http://community.topcoder.com/stat?c=problem_statement&pm=14075&rd=16552
// hint: implementation
// level: easy
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SetPartialOrder {
public:
	string compareSets(vector <int> a, vector <int> b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		bool ge = includes(a.begin(), a.end(), b.begin(), b.end());
		bool le = includes(b.begin(), b.end(), a.begin(), a.end());
		if(ge && le) {
			return "EQUAL";
		} else if(le) {
			return "LESS";
		} else if(ge) {
			return "GREATER";
		}
		return "INCOMPARABLE";
	}
};

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int na, nb, num;
		vector<int> a, b;
		cin >> na >> nb;
		for(int i = 0; i < na; ++i) {
			cin >> num;
			a.push_back(num);
		}
		for(int i = 0; i < nb; ++i) {
			cin >> num;
			b.push_back(num);
		}

		SetPartialOrder solver;
		cout << solver.compareSets(a, b) << endl;
	}
	return 0;
}
