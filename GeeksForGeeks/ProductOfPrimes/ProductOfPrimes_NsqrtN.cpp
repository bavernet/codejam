// problem: https://practice.geeksforgeeks.org/problems/product-of-primes/0
// hint: math
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

bool isPrime(int n, const vector<int> &p) {
	int limit = sqrt(n);
	for (auto pi : p) {
		if (pi > limit)
			break;
		if (n % pi == 0)
			return false;
	}
	return true;
}

int product(int l, int r, const vector<int> &p) {
	int ans = 1;
	for (int i = l; i <= r; ++i)
		if (isPrime(i, p))
			ans = mod(ans * i);
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
