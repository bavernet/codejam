#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

static inline bool isParentheses(char c) {
	return c == '(' || c == ')';
}

static inline bool isOperator(char c) {
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	};
	return false;
}

static inline int opcmp(const pair<int,char> &a, const pair<int,char> &b) {
	if (a.first != b.first)
		return a.first - b.first;
	if ((a.second == '+' || a.second == '-') && (b.second == '*' || b.second == '/'))
		return -1;
	if ((a.second == '*' || a.second == '/') && (b.second == '+' || b.second == '-'))
		return 1;
	return 0;
}

string toPostExpr(const string &expr) {
	string ans;
	stack<pair<int,char> > op;
	stack<char> sym;
	int level = 0;
	for (int i = 0, n = expr.size(); i < n; ++i) {
		if (isParentheses(expr[i])) {
			if (expr[i] == '(') ++level;
			else                --level;
			continue;
		}

		if (isOperator(expr[i])) {
			const auto cop = make_pair(level, expr[i]);
			if (op.empty() || opcmp(op.top(), cop) < 0) {
				ans.push_back(sym.top());
				sym.pop();
				op.push(cop);
			} else {
				while (!op.empty() && opcmp(op.top(), cop) >= 0) {
					if (!sym.empty()) {
						ans.push_back(sym.top());
						sym.pop();
					}
					ans.push_back(op.top().second);
					op.pop();
				}
				op.push(cop);
			}
		} else {
			sym.push(expr[i]);
		}
	}
	while (!op.empty()) {
		if (!sym.empty()) {
			ans.push_back(sym.top());
			sym.pop();
		}
		ans.push_back(op.top().second);
		op.pop();
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	string expr;
	cin >> expr;
	cout << toPostExpr(expr) << endl;
	return 0;
}
