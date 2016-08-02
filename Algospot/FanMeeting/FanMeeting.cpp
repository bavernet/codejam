// problem: https://algospot.com/judge/problem/read/FANMEETING
// hint: divide-and-conquer
// level: moderate
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define L_MAX   (200000)

void add(vector<int> &a, vector<int> &b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); ++i)
		a[i+k] += b[i];
}

void sub(vector<int> &a, vector<int> &b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); ++i)
		a[i] -= b[i];
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
	int na = a.size();
	int nb = b.size();
	if (na < nb)
		return karatsuba(b, a);
	if (na == 0 || nb == 0)
		return vector<int>();
	if (na == 1)
		return vector<int>(1, a[0] * b[0]);

	int half = na / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
	vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());

	vector<int> z0 = karatsuba(a0, b0);
	vector<int> z2 = karatsuba(a1, b1);
	add(a0, a1, 0);
	add(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	sub(z1, z0);
	sub(z1, z2);

	add(z0, z1, half);
	add(z0, z2, half + half);
	return z0;
}

int hugs(const string &star, const string &fan) {
	int n = star.size();
	int m = fan.size();

	vector<int> istar(n), ifan(m);
	for (int i = 0; i < star.size(); ++i)
		istar[i] = (star[i] == 'M');
	for (int i = 0; i < fan.size(); ++i)
		ifan[m - i - 1] = (fan[i] == 'M');

	vector<int> imul = karatsuba(ifan, istar);
	int ans = 0;
	for (int i = n - 1; i < m; ++i)
		if (!imul[i])
			++ans;
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		string star;
		string fan;
		cin >> star;
		cin >> fan;
		cout << hugs(star, fan) << endl;
	}

	return 0;
}
