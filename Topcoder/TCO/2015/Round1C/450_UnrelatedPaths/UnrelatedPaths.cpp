// problem: http://community.topcoder.com/stat?c=problem_statement&pm=13746&rd=16434
// hint: tree, implementation
// level: easy
#include <iostream>
#include <vector>

#define MAX_N   (50)

using namespace std;

class UnrelatedPaths {
public:
	int maxUnrelatedPaths(vector<int> parent) {
		vector<bool> hasChild(parent.size() + 1);
		for(int p : parent)
			hasChild[p] = true;

		int cnt = 0;
		for(bool b : hasChild)
			cnt += !b;

		return cnt;
	}
};

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;

		vector<int> parent;
		for(int i = 0; i < n; ++i) {
			int p;
			cin >> p;
			parent.push_back(p);
		}

		UnrelatedPaths solver;
		cout << solver.maxUnrelatedPaths(parent) << endl;
	}
	return 0;
}

