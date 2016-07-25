// problem: https://www.acmicpc.net/problem/11003
// hint: priority queue
// level: moderate
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
	cout.sync_with_stdio(false);
	int N, L, A;
	cin >> N >> L;

	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for (int i = 0; i < N; ++i) {
		cin >> A;
		pq.push(make_pair(A, i));

		pair<int,int> p = pq.top();
		while (p.second < i - L + 1) {
			pq.pop();
			p = pq.top();
		}
		cout << p.first << " ";
	}
	cout << endl;

	return 0;
}
