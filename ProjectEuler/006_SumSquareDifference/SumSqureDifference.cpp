// problem: https://projecteuler.net/problem=6
// hint: implement
// level: easy
#include <iostream>

#define MAX_T   (10000)
#define MAX_N   (10000)

using namespace std;

int64_t solve(int n) {
	int64_t squareSum = 0, sum = 0;
	for(int i = 1; i <= n; ++i) {
		squareSum += i * i;
		sum += i;
	}
	return ((sum * sum) - squareSum);
}

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}

	return 0;
}
