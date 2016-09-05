#include <iostream>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return n % 4;
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;

		Solution sol;
		cout << sol.canWinNim(n) << endl;
	}
	return 0;
}
