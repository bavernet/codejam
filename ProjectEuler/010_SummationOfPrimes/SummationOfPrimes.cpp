// problem: https://projecteuler.net/problem=10
// hint: math, prime, implementation
// level: easy
#include <iostream>
#include <vector>
#include <cmath>

#define MAX_T   (10000)
#define MAX_N   (2000000)

using namespace std;

bool mask[MAX_N+1] = { false, };
int64_t cache[MAX_N+1] = { 0, };

void filterPrime(int n) {
	int64_t sum = 0;
	for(int i = 2, e = sqrt(n) + 1; i < e; ++i) {
		if(mask[i])
			continue;
		sum += i;
		cache[i] += sum;
		for(int j = i + i; j <= n; j += i)
			mask[j] = true;
	}
	for(int i = sqrt(n) + 1; i <= n; ++i) {
		if(mask[i])
			continue;
		sum += i;
		cache[i] += sum;
	}
}

int64_t solve(int n) {
	for(int i = n; i >= 0; --i) {
		if(!mask[i]) {
			return cache[i];
		}
	}
	return 0;
}

int main(void) {
	int nTests;
	cin >> nTests;
	filterPrime(MAX_N);
	while(nTests--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
