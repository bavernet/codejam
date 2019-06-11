// problem: https://practice.geeksforgeeks.org/problems/euler-totient/0
// hint: math, prime number, totient
// level: easy
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N   (1000000000000LL)
vector<int> primes(int n) {
	vector<bool> sieve(n + 1);
	vector<int> spf(n + 1);
	vector<int> ans;
	for (int i = 2; i <= n; ++i) {
		if (!sieve[i]) {
			ans.push_back(i);
			spf[i] = i;
		}
		for (auto p : ans) {
			if (p > spf[i])
				break;
			if (i*p > n)
				break;
			sieve[i*p] = true;
			spf[i*p] = i;
		}
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);

	const vector<int> &p = primes(sqrt(MAX_N));
	vector<long long> ans;
	long long et = 1;
	for (auto pi : p) {
		ans.push_back(et);
		et *= pi;
		if (et > MAX_N)
			break;
	}

	int nTests;
	cin >> nTests;
	while (nTests--) {
		long long n;
		cin >> n;
		auto it = upper_bound(ans.begin(), ans.end(), n);
		cout << *prev(it) << '\n';
	}
	return 0;
}
