// problem: https://algospot.com/judge/problem/read/SUSHI
// hint: dp
// level: easy
#include <iostream>
#include <vector>

#define MAX_N       (20)
#define CACHE_SIZE  (0xFF)
#define index(i)    ((i) & CACHE_SIZE)

using namespace std;

int getMaxScore(const vector<int> &price, const vector<int> &pref, int money) {
	static vector<int> cache(CACHE_SIZE + 1);
	int n = price.size();
	cache[0] = 0;
	for (int i = 1; i <= money; ++i) {
		int score = 0;
		for (int j = 0; j < n; ++j)
			if (price[j] <= i)
				score = max(score, cache[index(i - price[j])] + pref[j]);
		cache[index(i)] = score;
	}
	return cache[index(money)];
}

int main(void) {
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n, m;
		cin >> n >> m;

		vector<int> price(n), preference(n);
		for (int i = 0; i < n; ++i) {
			cin >> price[i] >> preference[i];
			price[i] /= 100;
		}

		cout << getMaxScore(price, preference, m / 100) << endl;
	}

	return 0;
}
