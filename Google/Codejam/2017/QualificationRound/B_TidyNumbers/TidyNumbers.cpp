#include <iostream>
#include <string>
#include <vector>
using namespace std;

string tidy(string &num) {
	int n = num.size();
	vector<int> up;
	up.push_back(0);
	for (int i = 1; i < n; ++i) {
		if (num[i-1] < num[i]) {
			up.push_back(i);
		} else if (num[i-1] > num[i]) {
			--num[up.back()];
			for (int j = up.back() + 1; j < n; ++j)
				num[j] = '9';
			break;
		}
	}
	return (num[0] > '0')? num: num.substr(1);
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int i = 1; i <= nTests; ++i) {
		string num;
		cin >> num;
		cout << "Case #" << i << ": " << tidy(num) << '\n';
	}
	return 0;
}
