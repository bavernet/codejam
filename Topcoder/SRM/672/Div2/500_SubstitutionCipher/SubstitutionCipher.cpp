// problem: http://community.topcoder.com/stat?c=problem_statement&pm=14074&rd=16552
// hint: bitop, implementation
// level: easy
#include <iostream>
#include <string>

#define SZ_ALPHA    ('Z'-'A'+1)
#define IDX(c)      ((c)-'A')
#define CHAR(i)     ((i)+'A')
#define FULL_USED   (0x03FFFFFF)

using namespace std;

class SubstitutionCipher {
public:
	string decode(string a, string b, string y) {
		char dec[SZ_ALPHA] = { 0, };
		int bitsD = 0;
		int bitsE = 0;
		for(int i = 0; i < b.size(); ++i) {
			dec[IDX(b[i])] = a[i];
			bitsD |= (1 << IDX(b[i]));
			bitsE |= (1 << IDX(a[i]));
		}
		int unusedD = bitsD ^ FULL_USED;
		int unusedE = bitsE ^ FULL_USED;
		if(__builtin_popcount(unusedD) == 1) {
			int idx = __builtin_ctz(unusedD);
			dec[idx] = CHAR(__builtin_ctz(unusedE));
		}

		string org(y.size(), 0);
		for(int i = 0; i < y.size(); ++i) {
			char c = dec[IDX(y[i])];
			if(!c)
				return "";
			org[i] = c;
		}
		return org;
	}
};

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		string a, b, y;
		cin >> a >> b >> y;

		SubstitutionCipher solver;
		cout << solver.decode(a, b, y) << endl;
	}
	return 0;
}
