// problem: https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0
// hint: sieve of Eratosthenes
// level: easy
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;

vector<int> primes(int N) {
	vector<bool> prime(N + 1, true);
	vector<int> sf(N + 1);
	vector<int> ans;
	for (int i = 2; i <= N; ++i) {
		if (prime[i]) {
			ans.push_back(i);
			sf[i] = i;
		}

		for (auto p : ans) {
			if (p > sf[i])
				break;
			int ci = p * i;
			if (ci > N)
				break;
			prime[ci] = false;
			sf[ci] = p;
		}
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);

	const vector<int> &p = primes(MAX_N);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		for (auto pi : p) {
			if (pi > n)
				break;
			cout << pi << ' ';
		}
		cout << '\n';
	}
	return 0;
}
