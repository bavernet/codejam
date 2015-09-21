// problem: https://projecteuler.net/problem=12
// hint: math, implementation
// level: easy
#include <iostream>
#include <vector>
#include <cmath>

#define MAX_T   (10)
#define MAX_N   (1000)
#define MAX_TRI (42000)

using namespace std;

inline int countDivisors(int trinum) {
	int cnt = 0;
	for(int i = 1, e = sqrt(trinum) + 1; i < e; ++i) {
		if(trinum % i == 0) {
			cnt += 1 + (trinum != i * i);
		}
	}
	return cnt;
}

int solve(int n) {
	static int cache[MAX_TRI] = {0, };
	static int last = 0;
	static int tri = 0;
	for(int i = last + 1; cache[i-1] <= n; ++i, ++last) {
		tri += i;
		cache[i] = countDivisors(tri);
	}
	for(int i = 1; i < MAX_TRI; ++i) {
		if(cache[i] > n) {
			return i * (i + 1) / 2;
		}
	}
	return -1;
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
