// problem: https://algospot.com/judge/problem/read/BRUTEFORCE
// hint: greedy
// level: moderate
#include <iostream>

#define MOD         1000000007
#define mod(x)      (((unsigned long long)x) % MOD)

using namespace std;

int getCases(int a, int b, int n) {
	int ans = 1;
	while (a < b--)
		ans = mod(ans * n + 1);
	while (a--)
		ans = mod(ans * n);
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int A, B, N;
		cin >> A >> B >> N;
		cout << getCases(A, B, N) << endl;
	}

	return 0;
}
