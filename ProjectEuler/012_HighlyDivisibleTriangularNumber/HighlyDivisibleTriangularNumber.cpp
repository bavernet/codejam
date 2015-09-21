#include <iostream>
#include <limits>
#include <cmath>

#define MAX_T   (10)
#define MAX_N   (1000)

using namespace std;

int countDivisors(int64_t trinum) {
	int cnt = 0;
	for(int i = 1, e = sqrt(trinum) + 1; i < e; ++i) {
		if(trinum % i == 0) {
			cnt += 1 + (trinum != (int64_t)i * i);
		}
	}
	return cnt;
}

int64_t solve(int n) {
	int64_t sum = 0;
	for(int i = 1; i < numeric_limits<int>::max(); ++i) {
		sum += i;
		if(countDivisors(sum) > n)
			return sum;
	}
	return -1;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
