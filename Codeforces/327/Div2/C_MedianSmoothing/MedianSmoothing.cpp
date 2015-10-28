// problem: http://codeforces.com/contest/591/problem/C
// hint: greedy, implementation
// level: easy
#include <iostream>
#include <vector>

#define MAX_N   (500000)

using namespace std;

inline void fill(vector<bool> &a, int si, int ei) {
	for( ; si <= ei; ++si, --ei) {
		a[si] = a[si-1];
		a[ei] = a[ei+1];
	}
}

vector<bool> solve(vector<bool> a, int &maxDepth) {
	vector<bool> diff(a.size()), result(a.begin(), a.end());
	for(int i = 0; i + 1 < a.size(); ++i) {
		diff[i] = (a[i] != a[i+1]);
	}

	int cnt = 0, startIdx = 0;
	maxDepth = 0;
	for(int i = 0; i < diff.size(); ++i) {
		if(diff[i]) {
			if(cnt == 0)
				startIdx = i;
			++cnt;
		} else {
			maxDepth = max(maxDepth, cnt / 2);
			fill(result, startIdx + 1, startIdx + cnt - 1);
			cnt = 0;
		}
	}

	return result;
}

int main(void) {
	int n;
	cin >> n;

	vector<bool> a;
	for(int i = 0; i < n; ++i) {
		bool b;
		cin >> b;
		a.push_back(b);
	}

	int depth;
	vector<bool> result = solve(a, depth);
	cout << depth << endl;
	for(bool item : result) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}
