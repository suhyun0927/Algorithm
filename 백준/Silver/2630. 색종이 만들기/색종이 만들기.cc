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

int N;
int board[129][129]; // 2^7 = 128
int res[2];

void recur(int sy, int sx, int level) {
	int fin = N / (pow(2, level));

	int first = board[sy][sx];

	for (int i = sy; i < sy + fin; i++) {
		for (int j = sx; j < sx + fin; j++) {
			if (board[i][j] != first) {
				int interval = fin / 2;
				recur(sy, sx, level + 1);
				recur(sy + interval, sx, level + 1);
				recur(sy, sx + interval, level + 1);
				recur(sy + interval, sx + interval, level + 1);
				
				return;
			}
		}
	}

	res[first]++;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	recur(0, 0, 0);

	for (int i = 0; i < 2; i++) cout << res[i] << "\n";

	return 0;
}