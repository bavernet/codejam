// problem: https://projecteuler.net/problem=9
// hint: math, implementation
// level: easy
#include <iostream>

#define MAX_T   (3000)
#define MAX_N   (3000)

using namespace std;

int solve(int n) {
	int64_t answer = -1;
	for(int a = 1; a < n; ++a) {
		for(int b = a + 1; b < n; ++b) {
			int c = n - a - b;
			if(c <= b)
				break;
			if(a + b <= c) {
				b += (c - a - b) / 2;
			} else if(a*a + b*b == c*c) {
				answer = max(answer, (int64_t)a * b * c);
			}
		}
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
