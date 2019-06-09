// problem: https://practice.geeksforgeeks.org/problems/product-of-primes/0
// hint: math, segmented sieve
// level: medium
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_R   1000000000
#define M       1000000007
#define mod(x)  (((long long)x) % (M))

vector<int> primes(int n) {
	vector<bool> prime(n + 1, true);
	vector<int> spf(n + 1);
	vector<int> ans;
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			spf[i] = i;
			ans.push_back(i);
		}
		for (auto pi : ans) {
			if (pi > spf[i])
				break;
			if (pi * i > n)
				break;
			spf[pi*i] = pi;
			prime[pi*i] = false;
		}
	}
	return ans;
}

int product(int l, int r, const vector<int> &p) {
	int ans = 1;
	int n = r - l + 1;
	vector<bool> sieve(n);
	for (auto pi : p) {
		if (pi * pi > r)
			break;
		int begin = ((l + pi - 1) / pi) * pi;
		if (begin == pi)
			begin += pi;
		for (int i = begin - l; i < n; i += pi)
			sieve[i] = true;
	}
	for (int i = 0; i < n; ++i)
		if (!sieve[i])
			ans = mod(ans * (i + l));
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);

	const vector<int> &p = primes(sqrt(MAX_R));
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int l, r;
		cin >> l >> r;
		cout << product(l, r, p) << '\n';
	}
	return 0;
}
