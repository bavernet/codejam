// problem: http://community.topcoder.com/stat?c=problem_statement&pm=13717&rd=16433
// hint: tree, dfs, dp
// level: moderate
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N       (2000)
#define MOD         (1000000007)
#define ADD(a, b)   (((a) + (b)) % MOD)
#define SUB(a, b)   (((a) - (b) + MOD) % MOD)

using namespace std;

class TheTreeAndMan {
public:
	int solve(vector<int> parent) {
		for(int i = 0; i < parent.size(); ++i) {
			tree[i].clear();
		}
		memset(size, 0, sizeof(int)*(parent.size()+1));
		memset(legs, 0, sizeof(int)*(parent.size()+1));
		makeTree(parent);
		return findHead(0);
	}

private:
	int findHead(int root) {
		int cnt = 0;
		vector<int> &children = tree[root];
		for(int child : children) {
			cnt = ADD(cnt, findHead(child));
			cnt = ADD(cnt, findNeck(child));
		}
		return cnt;
	}

	int findNeck(int root) {
		int cnt = 0;
		vector<int> &children = tree[root];
		for(int child : children) {
			cnt = ADD(cnt, findNeck(child));
			cnt = ADD(cnt, (int64_t)findHeap(child) * findLegs(root, child));
		}
		return cnt;
	}

	int findHeap(int root) {
		int cnt = 0;
		vector<int> &children = tree[root];
		for(int child : children)
			cnt = ADD(cnt, findHeap(child));
		cnt = ADD(cnt, findLegs(root));
		return cnt;
	}

	int findLegs(int root) {
		int &cnt = legs[root];
		vector<int> &children = tree[root];
		if(cnt > 0)
			return cnt;

		for(int i = 0; i < children.size(); ++i) {
			for(int j = i + 1; j < children.size(); ++j) {
				cnt = ADD(cnt, getTreeSize(children[i]) * getTreeSize(children[j]));
			}
		}
		return cnt;
	}

	int findLegs(int root, int except) {
		vector<int> &children = tree[root];
		int cnt = findLegs(root);
		int exceptTreeSize = getTreeSize(except);
		for(int i = 0; i < children.size(); ++i) {
			if(children[i] == except)
				continue;
			cnt = SUB(cnt, getTreeSize(children[i]) * exceptTreeSize);
		}
		return cnt;
	}

	int getTreeSize(int root) {
		int &sz = size[root];
		if(sz > 0)
			return sz;

		vector<int> &children = tree[root];
		sz = 1;
		for(int child : children)
			sz += getTreeSize(child);
		return sz;
	}

	void makeTree(const vector<int> &parent) {
		for(int i = 0; i < parent.size(); ++i) {
			tree[parent[i]].push_back(i + 1);
		}
	}

private:
	vector<int> tree[MAX_N+1];
	int size[MAX_N+1];
	int legs[MAX_N+1];
};

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;

		vector<int> parent;
		for(int i = 0; i < n; ++i) {
			int p;
			cin >> p;
			parent.push_back(p);
		}

		TheTreeAndMan solver;
		cout << solver.solve(parent) << endl;
	}
	return 0;
}
