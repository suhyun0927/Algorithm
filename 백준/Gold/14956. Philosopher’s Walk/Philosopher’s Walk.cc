#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
using namespace std;

struct Node {
	int X;
	int Y;
};

int N, M;

Node solve(int M, int K) {
	if (K == 1) {
		if (M == 0)	return { 1,1 };
		if (M == 1)	return { 1,2 };
		if (M == 2)	return { 2,2 };
		if (M == 3)	return { 2,1 };
	}
	int p2 = 1 << K;
	int square = M / (1 << (2 * K - 2));
	Node coor = solve(M - square * (1 << (2 * K - 2)), K - 1);
	if (square == 0)
		return { coor.Y,coor.X };
	if (square == 1)
		return { coor.X,coor.Y + p2 / 2 };
	if (square == 2)
		return { coor.X + p2 / 2,coor.Y + p2 / 2 };
	return { p2 + 1 - coor.Y, p2 / 2 + 1 - coor.X };
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int K = 1;
	while (1 << K != N) K++;
	M--;
	
	Node ans = solve(M, K);

	cout << ans.X << " " << ans.Y;
}
