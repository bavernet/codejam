// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14182
// hint: greedy
// level: easy
#include <iostream>
#include <vector>

using namespace std;

class MoveStonesEasy {
public:
	int get(vector<int> a, vector<int> b) {
		int n = a.size();
		int ans = 0;
		for(int i = 0; i + 1 < n; ++i) {
			int need = b[i] - a[i];
			a[i+1] -= need;
			ans += abs(need);
		}
		return (a[n-1] == b[n-1])? ans : -1;
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];

		MoveStonesEasy solver;
		cout << solver.get(a, b) << endl;
	}
	return 0;
}
