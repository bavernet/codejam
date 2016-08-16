// problem: https://algospot.com/judge/problem/read/MATEXP
// hint: divide-and-conquer
// level: easy
#include <iostream>
#include <vector>

using namespace std;

#define MOD     10007
#define mod(x)  ((x) % MOD)

class Matrix {
	typedef vector<int> row;
	typedef vector<row> matrix;

private:
	int N;
	vector<row> mMat;
public:
	Matrix(int n): N(n), mMat(n, row(n)) { }

	Matrix mpow(int p) {
		if (p == 1)
			return *this;

		Matrix ans = mpow(p / 2);
		ans = ans * ans;
		if (p & 0x01)
			ans = *this * ans;
		return ans;
	}

	Matrix operator *(const Matrix &rm) {
		Matrix ans(N);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int &aij = ans.mMat[i][j];
				for (int k = 0; k < N; ++k) {
					aij = mod(aij + mMat[i][k] * rm.mMat[k][j]);
				}
			}
		}
		return ans;
	}

	friend istream &operator >>(istream &is, Matrix &m) {
		for (int i = 0; i < m.N; ++i)
			for (int j = 0; j < m.N; ++j)
				is >> m.mMat[i][j];
		return is;
	}

	friend ostream &operator <<(ostream &os, const Matrix &m) {
		for (int i = 0; i < m.N; ++i) {
			for (int j = 0; j < m.N; ++j)
				os << m.mMat[i][j] << " ";
			os << endl;
		}
		return os;
	}
};

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n, p;
		cin >> n >> p;

		Matrix mat(n);
		cin >> mat;
		cout << mat.mpow(p);
	}
	return 0;
}
