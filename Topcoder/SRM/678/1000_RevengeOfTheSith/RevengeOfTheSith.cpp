// problem: https://community.topcoder.com/stat?c=problem_statement&pm=13191&rd=16648
// hint: brute-force
// level: moderate
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class RevengeOfTheSith {
private:
	int getHarmPoints(const vector<int> &steps, int D) {
		int points = 0;
		for(int height : steps) {
			if(D < height) {
				points += (height - D) * (height - D);
			}
		}
		return points;
	}
public:
	int move(vector<int> steps, int T, int D) {
		if(T == 0)
			return getHarmPoints(steps, D);

		vector<int> s2(steps.begin(), steps.end());
		int answer = INT_MAX;
		for(int i = 0; i + 1 < s2.size(); ++i) {
			int limit = steps[i] + steps[i+1];
			for(int h = 1; h < limit; ++h) {
				s2[i] = h;
				s2[i+1] = steps[i] + steps[i+1] - h;
				answer = min(answer, move(s2, T - 1, D));
			}
			s2[i] = steps[i];
		}

		return answer;
	}
};

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int N, T, D;
		cin >> N;

		vector<int> steps(N);
		for(int i = 0; i < N; ++i) {
			cin >> steps[i];
		}
		cin >> T >> D;

		RevengeOfTheSith solver;
		cout << solver.move(steps, T, D) << endl;
	}

	return 0;
}
