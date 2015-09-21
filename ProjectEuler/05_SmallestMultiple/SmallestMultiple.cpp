// problem: https://projecteuler.net/problem=5
// hint: math, lcm
#include <iostream>
#include <algorithm>

#define MAX_T   (10)
#define MAX_N   (40)

using namespace std;

inline int64_t lcm(int64_t a, int64_t b) {
	return ((a * b) / __gcd(a, b));
}

inline int64_t solve(int n) {
	int64_t answer = 1;
	for(int i = 2; i <= n; ++i) {
		answer = lcm(answer, i);
	}
	return answer;
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
