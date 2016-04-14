// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14163
// hint: queue, combination, bfs, brute-force
// level: moderate
#include <iostream>
#include <string>
#include <queue>

#define MAX_LEN (2000)

using namespace std;

class TopBiologist {
private:
	const string DNA = "ACGT";

public:
	string findShortestNewSequence(string sequence) {
		queue<string> q;

		for (const char &unit : DNA)
			q.push(string(1, unit));

		while (!q.empty()) {
			string dna = q.front();
			q.pop();

			if (sequence.find(dna) == string::npos)
				return dna;

			for (const char &unit : DNA)
				q.push(dna + unit);
		}

		return string();
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while (nTests--) {
		string seq;
		cin >> seq;

		TopBiologist solver;
		cout << solver.findShortestNewSequence(seq) << endl;
	}

	return 0;
}
