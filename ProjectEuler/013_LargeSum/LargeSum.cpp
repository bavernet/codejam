// problem: https://projecteuler.net/problem=13
// hint: string, math, implementation
// level: easy
#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N   (1000)
#define MAX_LEN (54)    // 50 + 3
#define K       (10)
#define NUM(c)  ((c) - '0')
#define CHAR(n) ((n) + '0')

using namespace std;

inline string add(string a, string b) {
	string answer;
	if(a.size() < b.size()) swap(a, b);
	int minLen = b.size();
	int maxLen = a.size();
	bool overflow = false;
	for(int i = 0; i < minLen; ++i) {
		int sum = NUM(a[i]) + NUM(b[i]) + overflow;
		overflow = (sum >= 10);
		sum %= 10;
		answer.push_back(CHAR(sum));
	}
	for(int i = minLen; i < maxLen; ++i) {
		int sum = NUM(a[i]) + overflow;
		overflow = (sum >= 10);
		sum %= 10;
		answer.push_back(CHAR(sum));
	}
	if(overflow)
		answer.push_back('1');
	return answer;
}

int main(void) {
	string answer;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string a;
		cin >> a;
		reverse(a.begin(), a.end());
		answer = add(answer, a);
	}
	for(auto rit = answer.rbegin(), eit = answer.rbegin() + K; rit != eit; ++rit) {
		cout << (*rit);
	}
	cout << endl;
	return 0;
}
