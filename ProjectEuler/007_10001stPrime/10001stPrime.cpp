// problem: https://projecteuler.net/problem=7
// hint: math, prime, dynamic programming
// level: easy
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

#define MAX_T   (1000)
#define MAX_N   (10001)

using namespace std;

bool isPrime(const vector<int> &primes, int num) {
	int e = sqrt(num) + 1;
	for(int i = 0; i < primes.size() && primes[i] < e; ++i) {
		if(num % primes[i] == 0)
			return false;
	}
	return true;
}

int solve(int n) {
	static vector<int> primes = { 2 };
	for(int i = primes.size(); i <= n; ++i) {
		for(int j = primes.back() + 1; j <= numeric_limits<int>::max(); ++j) {
			if(isPrime(primes, j)) {
				primes.push_back(j);
				break;
			}
		}
	}
	return primes[n-1];
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
