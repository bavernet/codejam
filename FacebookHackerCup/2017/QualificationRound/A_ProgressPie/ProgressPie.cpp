#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Vector {
public:
	int x, y;
	Vector(int _x = 0, int _y = 0): x(_x), y(_y) { }

	Vector operator -(const Vector &b) const {
		return Vector(x - b.x, y - b.y);
	}

	int dot(const Vector &b) const {
		return x * b.x + y * b.y;
	}

	int cross(const Vector &b) const {
		return x * b.y - y * b.x;
	}

	double size(void) const {
		return sqrt(x*x + y*y);
	}

	double angle(const Vector &b) const {
		double al = size(), bl = b.size();
		double angle = acos(dot(b) / al / bl);
		if ((-cross(b)) < 0)
			angle = (-angle) + (2 * M_PI);
		return angle;
	}
};

const Vector center(50, 50);
const Vector top(50, 100);
const int rr = 50 * 50;
const Vector pivot = top - center;

static inline bool black(int percent, const Vector &p) {
	Vector v = p - center;
	if (rr < v.x*v.x + v.y*v.y)
		return false;

	double theta = pivot.angle(v);
	double limit = 2 * M_PI * percent / 100.0 + 0.000001;
	return theta <= limit;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		int p;
		Vector v;
		cin >> p >> v.x >> v.y;
		cout << "Case #" << t << ": " << (black(p, v)? "black": "white") << endl;
	}
	return 0;
}
