#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

static inline int guess(int a, int b) {
	return (a + b + 1) / 2;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int A, B, N;
		cin >> A >> B >> N;
		for (int i = 0; i < N; ++i) {
			string reply;
			int ans = guess(A, B);
			cout << ans << endl;
			cin >> reply;
			if (reply == "CORRECT")
				break;
			else if (reply == "TOO_SMALL")
				A = ans;
			else if (reply == "TOO_BIG")
				B = ans - 1;
			else {
				cerr << "reply: " << reply << endl;
				exit(1);
			}
		}
	}
	return 0;
}
