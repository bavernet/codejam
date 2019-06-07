#include <iostream>
#include <tuple>
using namespace std;

tuple<int,int,int> xgcd(int a, int b) {
	if (a == 0)
		return make_tuple(0, 1, b);
	int x, y, d;
	tie(x, y, d) = xgcd(b % a, a);
	return make_tuple(y - (b / a) * x, x, d);
}

int mod_inv(int a, int m) {
	int x, y, d;
	tie(x, y, d) = xgcd(a, m);
	if (d == 1)
		return (x + m) % m;
	return -1;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int a, m;
		cin >> a >> m;
		cout << mod_inv(a, m) << '\n';
	}
	return 0;
}
