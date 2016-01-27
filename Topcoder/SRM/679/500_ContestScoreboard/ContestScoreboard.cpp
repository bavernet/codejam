// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14124&rd=16649
// hint: implementation
// level: easy
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

class ContestScoreboard {
public:
	int findWinner(const vector<pair<int,string> > &sb) {
		int maxScore = max_element(sb.begin(), sb.end())->first;
		int win = -1;

		for(int i = 0; i < sb.size(); ++i) {
			if(maxScore != sb[i].first)
				continue;

			if(win < 0 || sb[i].second < sb[win].second) {
				win = i;
			}
		}

		return win;
	}

	vector <int> findWinner(vector <string> scores) {
		vector<pair<int,string> > scoreboard;
		vector<tuple<int,int,int> > submissions;
		for(int tid = 0; tid < scores.size(); ++tid) {
			istringstream ss(scores[tid]);
			string name;
			ss >> name;
			scoreboard.push_back(make_pair(0, name));

			int score, time;
			char dummy;
			while(ss >> score >> dummy >> time) {
				submissions.push_back(make_tuple(time, score, tid));
			}
		}

		vector<int> answer(scores.size());
		answer[findWinner(scoreboard)] = 1;
		sort(submissions.begin(), submissions.end());
		for(int i = 0; i < submissions.size(); ++i) {
			int time, score, tid;
			tie(time, score, tid) = submissions[i];
			scoreboard[tid].first += score;
			if(i + 1 == submissions.size() || time != get<0>(submissions[i+1]))
				answer[findWinner(scoreboard)] = 1;
		}

		return answer;
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		int N;
		cin >> N;
		getchar();

		vector<string> scores(N);
		for(int i = 0; i < N; ++i) {
			getline(cin, scores[i]);
		}

		ContestScoreboard solver;
		vector<int> answer = solver.findWinner(scores);
		for(int win : answer)
			cout << win << " ";
		cout << endl;
	}

	return 0;
}
