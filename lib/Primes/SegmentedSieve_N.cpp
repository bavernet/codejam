// problem: https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0
// hint: math, segmented sieve
// level: easy
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N   1000000000
#define M       1000000007
#define mod(x)  (((long long)x) % (M))

vector<int> primes(int n) {
	vector<int> ans;
	int units = ceil(sqrt(n + 1));
	vector<bool> sieve(units);
	vector<int> spf(units);
	for (int i = 2; i < units; ++i) {
		if (!sieve[i]) {
			ans.push_back(i);
			spf[i] = i;
		}
		for (auto pi : ans) {
			if (pi > spf[i])
				break;
			int ci = pi * i;
			if (ci >= units)
				break;
			sieve[ci] = true;
			spf[ci] = pi;
		}
	}

	for (int begin = units, end = units + units; begin < n; begin += units, end += units) {
		fill(sieve.begin(), sieve.end(), false);
		for (auto pi : ans) {
			if (pi * pi >= end)
				break;
			int left = ceil(begin * 1.0 / pi) * pi;
			if (left == pi)
				left += pi;
			for (int i = left; i < end; i += pi)
				sieve[i-begin] = true;
		}
		for (int i = 0; i < units; ++i)
			if (!sieve[i])
				ans.push_back(i + begin);
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		const vector<int> &p = primes(n);
		cout << p.size() << endl;
		for (auto pi : p)
			cout << pi << ' ';
		cout << '\n';
	}

	return 0;
}
