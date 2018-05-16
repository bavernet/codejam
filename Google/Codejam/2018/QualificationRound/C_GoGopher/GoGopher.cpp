#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

class rect {
private:
	int w, h, ti, tj;
	vector<vector<bool> > a;

	bool completed(void) {
		for (int i = ti - 1; i <= ti + 1; ++i)
			for (int j = tj - 1; j <= tj + 1; ++j)
				if (!a[i][j])
					return false;
		return true;
	}

public:
	rect(int _w, int _h): w(_w), h(_h), ti(2), tj(2), a(_h + 1, vector<bool>(_w + 1)) {
	}

	tuple<int,int> next(int r, int c) {
		if (a[r][c])
			return make_tuple(ti, tj);
		a[r][c] = true;
		if (completed()) {
			if (tj + 1 == w) {
				/* change ti */
				tj = 2;
				ti = min(ti + 3, h - 1);
			} else {
				/* change tj */
				tj = min(tj + 3, w - 1);
			}
		}
		return make_tuple(ti, tj);
	}
};

rect make_rect(int area) {
	int w, h;
	if (area <= 9)
		return rect(3, 3);
	if (area <= 3000) {
		h = 3;
		w = (area + 2) / 3;
	} else {
		int r = sqrt(area);
		if (r * r < area)
			++r;
		w = r;
		h = r;
	}
	return rect(w, h);
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int a;
		cin >> a;
		int i = 2, j = 2;
		rect &&r = make_rect(a);
		while (true) {
			int ii, jj;
			cout << i << ' ' << j << endl;
			cin >> ii >> jj;
			if (ii < 0 && jj < 0)
				return 0;
			if (ii == 0 && jj == 0)
				break;
			tie(i, j) = r.next(ii, jj);
		}
	}
	return 0;
}
