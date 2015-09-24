// problem: https://www.hackerrank.com/contests/projecteuler/challenges/euler017
// hint: string, recursive, implementation
// level: easy
#include <iostream>
#include <map>
#include <string>

#define MAX_T   (10)
#define MAX_N   (1000000000000LL)

using namespace std;

map<int64_t, string> cardinalNumber = {
	{ 0, "Zero" }, { 1, "One" }, { 2, "Two" }, { 3, "Three" }, { 4, "Four" },
	{ 5, "Five" }, { 6, "Six" }, { 7, "Seven" }, { 8, "Eight" }, { 9, "Nine" },
	{ 10, "Ten" }, { 11, "Eleven" }, { 12, "Twelve" }, { 13, "Thirteen" },
	{ 14, "Fourteen" }, { 15, "Fifteen" }, { 16, "Sixteen" },
	{ 17, "Seventeen" }, { 18, "Eighteen" }, { 19, "Nineteen" },
	{ 20, "Twenty" }, { 30, "Thirty" }, { 40, "Forty" }, { 50, "Fifty" },
	{ 60, "Sixty" }, { 70, "Seventy" }, { 80, "Eighty" }, { 90, "Ninety" },
	{ 100, "Hundred" }, { 1000, "Thousand" }, { 1000000, "Million" },
	{ 1000000000LL, "Billion" }, { 1000000000000LL, "Trillion" }
};

string solve(int64_t n) {
	if(n <= 20)
		return (cardinalNumber[n] + " ");

	string answer;
	for(auto rit = cardinalNumber.rbegin(); n >= 100 && rit != cardinalNumber.rend(); ++rit) {
		int64_t quotient = n / rit->first;
		if(quotient > 0) {
			answer += solve(quotient) + rit->second + " ";
			n %= rit->first;
		}
	}
	if(n > 0) {
		for(int i = 90; i >= 20; i -= 10) {
			int quotient = n / i;
			if(quotient > 0) {
				answer += cardinalNumber[i] + " ";
				n %= i;
			}
		}
		if(n > 0) {
			answer += cardinalNumber[n] + " ";
		}
	}
	return answer;
}


int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int64_t n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
