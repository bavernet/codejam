// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14123&rd=16649
// hint: implementation
// level: easy
#include <iostream>
#include <vector>

using namespace std;

class ListeningSongs {
public:
	int listen(vector<int> durations1, vector<int> durations2, int minutes, int T) {
		if(durations1.size() < T || durations2.size() < T)
			return -1;

		sort(durations1.begin(), durations1.end());
		sort(durations2.begin(), durations2.end());

		int available = minutes * 60;
		for(int i = 0; i < T; ++i) {
			available -= durations1[i] + durations2[i];
		}

		if(available < 0)
			return -1;

		int cnt = 2*T;
		vector<int> remains(durations1.begin() + T, durations1.end());
		remains.insert(remains.end(), durations2.begin() + T, durations2.end());
		sort(remains.begin(), remains.end());
		for(int song : remains) {
			if(available - song < 0)
				break;
			available -= song;
			++cnt;
		}
		return cnt;
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		int nD1, nD2, minutes, T;
		cin >> nD1 >> nD2 >> minutes >> T;

		vector<int> durations1(nD1), durations2(nD2);
		for(int i = 0; i < nD1; ++i)
			cin >> durations1[i];
		for(int i = 0; i < nD2; ++i)
			cin >> durations2[i];

		ListeningSongs solver;
		cout << solver.listen(durations1, durations2, minutes, T) << endl;
	}

	return 0;
}
