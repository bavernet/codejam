// problem: https://projecteuler.net/problem=8
// hint: implementation
// level: easy
#include <iostream>
#include <string>

#define MAX_T   (100)
#define MAX_K   (7)
#define MAX_N   (1000)

using namespace std;

int64_t solve(string s, int k) {
	int64_t answer = 0;
	int n = s.size();
	for(int i = 0; i + k < n; ++i) {
		int64_t product = 1;
		for(int j = i, e = i + k; j < e; ++j) {
			product *= (s[j] - '0');
		}
		answer = max(answer, product);
	}
	return answer;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n, k;
		string series;
		cin >> n >> k;
		cin >> series;
		cout << solve(series, k) << endl;
	}
	return 0;
}
