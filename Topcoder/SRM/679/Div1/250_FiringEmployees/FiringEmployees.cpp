// problem: https://community.topcoder.com/stat?c=problem_statement&pm=14122&rd=16649
// hint: tree traversal, divide and conquer
// level: easy
#include <iostream>
#include <vector>

using namespace std;

class FiringEmployees {
public:
	int getMaxProfits(int root, const vector<vector<int> > &tree,
					  const vector<int> &salary, const vector<int> &productivity) {
		const vector<int> &children = tree[root];
		int myProfit = (root > 0)? (productivity[root-1] - salary[root-1]) : 0;
		if(children.empty())
			return (myProfit > 0)? myProfit : 0;

		for(int child : children) {
			myProfit += getMaxProfits(child, tree, salary, productivity);
		}

		return (myProfit > 0)? myProfit : 0;
	}

	int fire(vector<int> manager, vector<int> salary, vector<int> productivity) {
		int N = manager.size();
		vector<vector<int> > tree(N + 1);
		for(int i = 0; i < N; ++i) {
			tree[manager[i]].push_back(i + 1);
		}

		return getMaxProfits(0, tree, salary, productivity);
	}
};

int main(void) {
	cout.sync_with_stdio(false);

	int nTests;
	cin >> nTests;
	while(nTests--) {
		int N;
		cin >> N;

		vector<int> manager(N), salary(N), productivity(N);
		for(int i = 0; i < N; ++i)
			cin >> manager[i];
		for(int i = 0; i < N; ++i)
			cin >> salary[i];
		for(int i = 0; i < N; ++i)
			cin >> productivity[i];

		FiringEmployees solver;
		cout << solver.fire(manager, salary, productivity) << endl;
	}

	return 0;
}
