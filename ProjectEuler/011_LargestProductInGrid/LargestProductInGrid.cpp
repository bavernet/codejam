// problem: https://projecteuler.net/problem=11
// hint: data structure, implementation
// level: easy
#include <iostream>
#include <algorithm>

#define N   (20)
#define K   (4)

using namespace std;

enum { RIGHT = 0, RIGHTDOWN, DOWN, LEFTDOWN, N_DIR };
enum { X = 0, Y, XY };
int gDir[N_DIR][XY] = {
	{ 1, 0 },   // RIGHT
	{ 1, 1 },   // RIGHTDOWN
	{ 0, 1 },   // DOWN
	{ -1, 1 },  // LEFTDOWN
};

int getMaxProduct(int grid[N][N], int x, int y) {
	int maxProduct = 0;
	for(int dir = 0; dir < N_DIR; ++dir) {
		int cnt = 0, product = 1;
		for(int i = y, j = x; i >= 0 && i < N && j >= 0 && j < N && cnt < K; ++cnt) {
			product *= grid[i][j];
			i += gDir[dir][Y];
			j += gDir[dir][X];
		}
		if(cnt == K) {
			maxProduct = max(maxProduct, product);
		}
	}
	return maxProduct;
}

int solve(int grid[N][N]) {
	int answer = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			answer = max(answer, getMaxProduct(grid, j, i));
		}
	}
	return answer;
}

int main(void) {
	int grid[N][N];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cin >> grid[i][j];
		}
	}
	cout << solve(grid) << endl;
	return 0;
}
