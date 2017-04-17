// problem: https://www.acmicpc.net/problem/4195
// hint: disjoint-set
// level: easy
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string root(const string &a, map<string,string> &parent) {
	if (parent.find(a) == parent.end())
		return a;
	return parent[a] = root(parent[a], parent);
}

vector<int> network(const vector<string> &a, const vector<string> &b) {
	int n = a.size();
	vector<int> ans(n);
	map<string,string> parent;
	map<string,int> size;
	for (int i = 0; i < n; ++i) {
		string ar = root(a[i], parent);
		string br = root(b[i], parent);
		if (!size[ar]) size[ar] = 1;
		if (!size[br]) size[br] = 1;
		if (ar != br) {
			parent[ar] = br;
			size[br] += size[ar];
		}
		ans[i] = size[br];
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<string> a(n), b(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];
		vector<int> &&sz = network(a, b);
		for (auto s : sz)
			cout << s << endl;
	}
	return 0;
}
