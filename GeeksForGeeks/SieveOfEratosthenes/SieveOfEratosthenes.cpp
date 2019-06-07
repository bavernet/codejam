// problem: https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0
// hint: sieve of Eratosthenes
// level: easy
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10001;

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> prime(MAX_N, true);
	for (int i = 2; i < MAX_N; ++i) {
		if (!prime[i])
			continue;
		for (int j = i + i; j < MAX_N; j += i)
			prime[j] = false;
	}

	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		for (int i = 2; i <= n; ++i)
			if (prime[i])
				cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
