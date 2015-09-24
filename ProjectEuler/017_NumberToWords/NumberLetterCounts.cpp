// problem: https://projecteuler.net/problem=17
// hint: math, recursive, implementation
// level: easy
#include <iostream>
#include <map>

#define MAX_T   (10)
#define MAX_N   (1000)

using namespace std;

map<int, int> cardinalNumber = {
	{ 1, 3 }, { 2, 3 }, { 3, 5 }, { 4, 4 }, { 5, 4 },
	{ 6, 3 }, { 7, 5 }, { 8, 5 }, { 9, 4 }, { 10, 3 },
	{ 11, 6 }, { 12, 6 }, { 13, 8 }, { 14, 8 }, { 15, 7 },
	{ 16, 7 }, { 17, 9 }, { 18, 8 }, { 19, 8 }, { 20, 6 },
	{ 30, 6 }, { 40, 5 }, { 50, 5 }, { 60, 5 }, { 70, 7 },
	{ 80, 6 }, { 90, 6 }, { 100, 7 }, { 1000, 8 }
};

int solve(int n) {
	if(n <= 20)
		return cardinalNumber[n];

	int answer = 0;
	if(n / 1000) {
		answer += cardinalNumber[n/1000] + cardinalNumber[1000];
		n %= 1000;
		if(n > 0)
			answer += 3;
	}
	if(n / 100) {
		answer += cardinalNumber[n/100] + cardinalNumber[100];
		n %= 100;
		if(n > 0)
			answer += 3;
	}
	for(int i = 90; i >= 20; i -= 10) {
		if(n / i) {
			answer += cardinalNumber[i];
			n %= i;
			break;
		}
	}
	if(n > 0) {
		answer += cardinalNumber[n];
	}
	return answer;
}


int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int a, b;
		int sum = 0;
		cin >> a >> b;
		for(int i = a; i <= b; ++i) {
			sum += solve(i);
		}
		cout << sum << endl;
	}
	return 0;
}
