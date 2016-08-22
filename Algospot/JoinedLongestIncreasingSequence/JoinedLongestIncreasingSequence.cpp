// problem: https://algospot.com/judge/problem/read/JLIS
// hint: dp, binary-search
// level: easy
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int getMaxLIS(vector<int> &a, vector<int> &is) {
	int n = a.size();
	vector<int> lis;
	for (int i = 0; i < n; ++i) {
		if (binary_search(is.begin(), is.end(), a[i]))
			continue;

		vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), a[i]);
		if (it != lis.end())
			*it = a[i];
		else
			lis.push_back(a[i]);
	}
	return lis.size();
}

int getMaxJLIS(vector<int> &a, vector<int> &b) {
	set<int> sa(a.begin(), a.end());
	set<int> sb(b.begin(), b.end());
	vector<int> intersect, empty;
	set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), back_inserter(intersect));
	return max(getMaxLIS(a, intersect) + getMaxLIS(b, empty),
			   getMaxLIS(a, empty) + getMaxLIS(b, intersect));
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n, m;
		cin >> n >> m;

		vector<int> A(n), B(m);
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		for (int i = 0; i < m; ++i)
			cin >> B[i];

		cout << getMaxJLIS(A, B) << endl;
	}
	return 0;
}
