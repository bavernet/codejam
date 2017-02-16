// problem: http://codeforces.com/contest/765/problem/C
// hint: math
// level: easy
#include <iostream>

using namespace std;

int getSets(int a, int b, int k) {
	int aw = a / k, bw = b / k;
	int ar = a % k, br = b % k;
	int ns = aw + bw;
	if (ns == 0 || (ar && !bw) || (br && !aw))
		return -1;
	return ns;
}

int main(void) {
	cout.sync_with_stdio(false);
	int k, a, b;
	cin >> k >> a >> b;
	cout << getSets(a, b, k) << endl;
	return 0;
}
