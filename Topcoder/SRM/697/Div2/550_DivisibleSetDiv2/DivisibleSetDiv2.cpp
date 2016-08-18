// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14369&rd=16776
// hint: math
// level: moderate
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DivisibleSetDiv2 {
public:
	string isPossible(vector<int> b) {
		int total = 3628800;
		int sum = 0;
		for (int i = 0; i < b.size(); ++i)
			sum += total / b[i];
		return (sum <= total)? "Possible": "Impossible";
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;

		vector<int> b(n);
		for (int i = 0; i < n; ++i)
			cin >> b[i];

		DivisibleSetDiv2 sol;
		cout << sol.isPossible(b) << endl;
	}
	return 0;
}
