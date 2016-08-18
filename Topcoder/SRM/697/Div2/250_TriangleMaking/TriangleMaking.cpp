// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14371&rd=16776
// hint: math
// level: easy
#include <iostream>
#include <vector>

using namespace std;

class TriangleMaking {
public:
	int maxPerimeter(int a, int b, int c) {
		vector<int> sides = {a, b, c};
		sort(sides.begin(), sides.end());
		int sum = sides[0] + sides[1];
		return sum + min(sum - 1, sides[2]);
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int a, b, c;
		cin >> a >> b >> c;

		TriangleMaking sol;
		cout << sol.maxPerimeter(a, b, c) << endl;
	}
	return 0;
}
