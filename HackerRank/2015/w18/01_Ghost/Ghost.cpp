// problem: https://www.hackerrank.com/contests/w18/challenges/ghosts
// hint: implementation
// level: easy
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solve(int A, int B, int C, int D) {
	int answer = 0;

	for(int a = 1; a <= A; ++a) {
		for(int b = 1; b <= B; ++b) {
			if(abs(a - b) % 3)
				continue;

			for(int c = 1; c <= C; ++c) {
				if((b + c) % 5)
					continue;

				if((a * c) % 4)
					continue;

				for(int d = 1; d <= D; ++d) {
					if(__gcd(a, d) == 1)
						++answer;
				}
			}
		}
	}

	return answer;
}

int main(void) {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << solve(A, B, C, D) << endl;

	return 0;
}
