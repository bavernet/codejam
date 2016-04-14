// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14163
// hint: optimize, string, brute-force
// level: moderate
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_LEN (2000)

using namespace std;

class TopBiologist {
private:
	string DNA = "AGCT";

	void fill(vector<string> &dnas, string &s, int limit) {
		if (s.size() > limit)
			return ;

		for (int i = 0; i < DNA.size(); ++i) {
			s.push_back(DNA[i]);
			dnas.push_back(s);
			fill(dnas, s, limit);
			s.pop_back();
		}
	}

public:
	string findShortestNewSequence(string sequence) {
		vector<string> DNAs;
		string tmp;
		fill(DNAs, tmp, 6);
		sort(DNAs.begin(), DNAs.end(), [&](const string &a, const string &b) {
			if (a.size() == b.size())
				return a < b;
			return a.size() < b.size();
		});

		for (string &dna : DNAs) {
			if (sequence.find(dna) == string::npos)
				return dna;
		}

		return string(2001, 'A');
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
