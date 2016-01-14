// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14115&rd=16648
// hint: implementation
// level: easy
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class ThePhantomMenace {
public:
	int find(vector<int> doors, vector<int> droids) {
		int safety = 0;
		for(int i = 0; i < doors.size(); ++i) {
			int dist = INT_MAX;
			for(int j = 0; j < droids.size(); ++j) {
				dist = min(dist, abs(doors[i] - droids[j]));
			}
			safety = max(safety, dist);
		}
		return safety;
	}
};

int main(void) {
	int nTests, nDoors, nDroids;
	cin >> nTests;
	while(nTests--) {
		cin >> nDoors >> nDroids;

		vector<int> doors(nDoors), droids(nDroids);
		for(int i = 0; i < nDoors; ++i) {
			cin >> doors[i];
		}
		for(int i = 0; i < nDroids; ++i) {
			cin >> droids[i];
		}

		ThePhantomMenace solver;
		cout << solver.find(doors, droids) << endl;
	}

	return 0;
}
