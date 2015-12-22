// problem: https://www.hackerrank.com/contests/w18/challenges/target
// hint: sort, geometry
// level: easy
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

int64_t solve(vector<int64_t> &RR, vector<vector<int> > &shot) {
	int64_t score = 0;
	int N = shot.size();
	for(int i = 0; i < N; ++i) {
		int64_t x = shot[i][0];
		int64_t y = shot[i][1];
		int64_t rr = x*x + y*y;
		auto it = upper_bound(RR.begin(), RR.end(), rr, greater<int64_t>());
		score += distance(RR.begin(), it);
	}
	return score;
}

int main(){
	int K;
	int N;
	int64_t r;
	cin >> K >> N;

	vector<int64_t> RR(K);
	for(int i = 0; i < K; i++){
		cin >> r;
		RR[i] = r * r;
	}

	vector<vector<int> > x(N, vector<int>(2));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 2; j++){
			cin >> x[i][j];
		}
	}

	cout << solve(RR, x) << endl;

	return 0;
}
