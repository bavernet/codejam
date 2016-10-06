// problem: https://algospot.com/judge/problem/read/WEIRD
// hint: dp, math
// level: moderate
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool weird(int n) {
	vector<int> div;
	div.push_back(1);
	int sum =1;
	for (int d = 2, e = sqrt(n) + 1; d < e; ++d) {
		if (n % d)  continue;
		div.push_back(d);
		div.push_back(n / d);
		sum += n / d + d;
	}

	if (sum <= n)
		return false;

	sort(div.begin(), div.end());
	vector<bool> dp(n + 1);
	for (int &d : div) {
		for (int i = n; i > 0; --i)
			if (dp[i] && i+d <= n)
				dp[i+d] = true;
		dp[d] = true;
		if (dp[n])
			return false;
	}
	return true;
}

int main(void) {
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		cout << ((weird(n))? "weird": "not weird") << endl;
	}
	return 0;
}
