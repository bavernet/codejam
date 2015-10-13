// problem: http://codeforces.com/contest/586/problem/C
// hint: greedy, implementation
// level: easy
#include <iostream>
#include <vector>

#define MAX_N   (4000)

using namespace std;

int64_t vi[MAX_N+1];
int64_t di[MAX_N+1];
int64_t pi[MAX_N+1];

int main(void) {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> vi[i] >> di[i] >> pi[i];
	}

	vector<int> curedChildren;
	for(int i = 1; i <= n; ++i) {
		if(pi[i] < 0)
			continue;

		curedChildren.push_back(i);
		int64_t u = 0;
		for(int j = i + 1, vol = vi[i]; j <= n; ++j) {
			if(pi[j] < 0)
				continue;

			pi[j] -= u + max(0, vol--);
			if(pi[j] < 0) {
				u += di[j];
			}
		}
	}

	cout << curedChildren.size() << endl;
	for(int child : curedChildren) {
		cout << child << " ";
	}
	cout << endl;

	return 0;
}
