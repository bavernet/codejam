// problem: https://community.topcoder.com/stat?c=problem_statement&pm=13586&rd=16648
// hint: greedy
// level: easy
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class AttackOfTheClones {
public:
	int count(vector<int> firstWeek, vector<int> lastWeek) {
		map<int,int> firstPos;
		for(int i = 0; i < firstWeek.size(); ++i) {
			firstPos[firstWeek[i]] = i;
		}

		int numOfWeeks = 0;
		for(int i = 0; i < lastWeek.size(); ++i) {
			numOfWeeks = max(numOfWeeks, firstPos[lastWeek[i]] - i);
		}

		return numOfWeeks + 1;
	}
};

int main(void) {
	int nTests, N;
	cin >> nTests;
	while(nTests--) {
		cin >> N;

		vector<int> firstWeek(N), lastWeek(N);
		for(int i = 0; i < N; ++i) {
			cin >> firstWeek[i];
		}
		for(int i = 0; i < N; ++i) {
			cin >> lastWeek[i];
		}

		AttackOfTheClones solver;
		cout << solver.count(firstWeek, lastWeek) << endl;
	}

	return 0;
}
