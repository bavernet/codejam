// problem: https://www.acmicpc.net/problem/1918
// hint: stack
// level: medium
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string toPostExpr(string &expr) {
	string ans;
	stack<char> op;
	op.push('(');
	expr.push_back(')');
	for (auto c : expr) {
		if (isalpha(c)) {
			ans.push_back(c);
		} else if (c == '(') {
			op.push(c);
		} else if (c == ')') {
			while (op.top() != '(') {
				ans.push_back(op.top());
				op.pop();
			}
			op.pop();
		} else {
			while (op.top() != '('
				   && !((op.top() == '+' || op.top() == '-') && (c == '*' || c == '/'))) {
				ans.push_back(op.top());
				op.pop();
			}
			op.push(c);
		}
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
