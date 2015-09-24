// problem: https://projecteuler.net/problem=17
// hint: math, big integer, dp
// level: easy
#include <iostream>
#include <string>

#define MAX_T   (100)
#define MAX_N   (10000)
#define CHAR(d) ((d) + '0')
#define INT(c)  ((c) - '0')

using namespace std;

int cache[MAX_N+1] = { 0, };

void squre(string &num) {
	bool overflow = false;
	for(int i = 0; i < num.size(); ++i) {
		int mul = INT(num[i]) * 2 + overflow;
		overflow = (mul >= 10);
		num[i] = CHAR(mul % 10);
	}
	if(overflow) {
		num.push_back('1');
	}
}

int digitSum(const string &num) {
	int sum = 0;
	for(char c : num) {
		sum += INT(c);
	}
	return sum;
}

int solve(int n) {
	if(cache[n] > 0)
		return cache[n];

	string powerNum = "1";
	cache[0] = 1;
	for(int i = 1; i <= n; ++i) {
		squre(powerNum);
		cache[i] = digitSum(powerNum);
	}

	return cache[n];
}

int main(void) {
	int nTests;
	cin >> nTests;
	solve(MAX_N);
	while(nTests--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
