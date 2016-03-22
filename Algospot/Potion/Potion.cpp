// problem: https://algospot.com/judge/problem/read/POTION
// hint: math
// level: easy
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline int getGCD(const vector<int> &recipe) {
	int gcd = recipe[0];
	for(int r : recipe)
		gcd = __gcd(gcd, r);
	return gcd;
}

vector<int> getNeeds(vector<int> &recipe, vector<int> &past) {
	int n = recipe.size();
	vector<int> needs(n);
	int base = getGCD(recipe);
	int nPotions = base;
	for(int i = 0; i < n; ++i) {
		recipe[i] /= base;
		nPotions = max(nPotions, (int)ceil((double)past[i] / recipe[i]));
	}

	for(int i = 0; i < n; ++i)
		needs[i] = recipe[i] * nPotions - past[i];

	return needs;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;

		vector<int> r(n), p(n);
		for(int i = 0; i < n; ++i)
			cin >> r[i];
		for(int i = 0; i < n; ++i)
			cin >> p[i];

		vector<int> needs = getNeeds(r, p);
		for(int s : needs)
			cout << s << " ";
		cout << endl;
	}

	return 0;
}
