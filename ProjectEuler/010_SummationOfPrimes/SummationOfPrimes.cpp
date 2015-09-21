// problem: https://projecteuler.net/problem=10
// hint: math, prime, implementation
// level: easy
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define MAX_T   (10000)
#define MAX_N   (2000000)

using namespace std;

bool mask[MAX_N+1] = { false, };
map<int,int64_t> cache = { { 2, 2 } };

void filterPrime(int n) {
	for(int i = 2, e = sqrt(n) + 1; i < e; ++i) {
		if(mask[i])
			continue;
		for(int j = i + i; j <= n; j += i)
			mask[j] = true;
	}
}

int64_t solve(int n) {
	auto it = cache.upper_bound(n);
	--it;
	int64_t sum = it->second;
	for(int i = it->first + 1; i <= n; ++i) {
		if(mask[i])
			continue;
		sum += i;
		cache[i] = sum;
	}
	return sum;
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
