// problem: https://algospot.com/judge/problem/read/PICNIC
// hint: brute-force
// level: easy
#include <iostream>
#include <set>
#include <cassert>
#include <cstring>

#define MAX_C   (50)
#define MAX_N   (10)
#define MAX_M   (MAX_N * (MAX_N + 1) / 2)

using namespace std;

bool friends[MAX_N][MAX_N];

int solve(set<int> &s) {
	assert(s.size() % 2 == 0);

	if(s.size() == 2) {
		int a = *s.begin();
		int b = *++s.begin();
		return friends[a][b];
	}

	int ans = 0;
	int a = *s.begin(), b;
	s.erase(s.begin());
	for(int i = 0; i < s.size(); ++i) {
		auto it = next(s.begin(), i);
		b = *it;
		if(friends[a][b]) {
			s.erase(it);
			ans += solve(s);
			s.insert(b);
		}
	}
	s.insert(a);

	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n, m;
		cin >> n >> m;

		memset(friends, 0, sizeof(friends));
		for(int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			friends[a][b] = friends[b][a] = true;
		}

		set<int> students;
		for(int i = 0; i < n; ++i)
			students.insert(i);

		cout << solve(students) << endl;
	}

	return 0;
}
