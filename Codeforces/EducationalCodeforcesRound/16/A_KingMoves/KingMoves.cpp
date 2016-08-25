 // problem: http://codeforces.com/contest/710/problem/A
 // hint: implementation
 // level: easy
#include <iostream>
#include <string>

using namespace std;

int getKingMoves(string &pos) {
	int ans = 8;
	if (pos[0] == 'a' || pos[0] == 'h')
		ans -= 3;
	if (pos[1] == '1' || pos[1] == '8')
		ans -= 3;
	return (ans == 2)? 3: ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	string pos;
	cin >> pos;
	cout << getKingMoves(pos) << endl;
	return 0;
}
