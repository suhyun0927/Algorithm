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
#include <map>
using namespace std;

int N, M, K;
int col, row;
int arr[40][40];
int sticker[10][10];
int copy_sticker[10][10];
int flag;

void placeSticker(int sy, int sx, int dir) {
	// rotate
	if (dir == 0) {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				copy_sticker[i][j] = sticker[i][j];
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				copy_sticker[j][col-1-i] = sticker[i][j];
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				copy_sticker[col-1-i][row-1-j] = sticker[i][j];
			}
		}
	}
	else { // dir = 3
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				copy_sticker[row-1-j][i] = sticker[i][j];
			}
		}
	}

	int h = col, w = row;
	if (dir == 1 || dir == 3) h = row, w = col;

	// 범위 확인
	if (sy + h > N || sx + w > M) return;

	// 확인 중
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (copy_sticker[i][j] == 1 && arr[sy + i][sx + j] == 1) return;
		}
	}

	// 붙이기
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (copy_sticker[i][j] == 0) continue;
			arr[sy + i][sx + j] = 1;
		}
	}

	flag = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		// input
		cin >> col >> row;

		for (int j = 0; j < col; j++) {
			for (int k = 0; k < row; k++) {
				cin >> sticker[j][k];
			}
		}

		// 빈 공간 찾기
		flag = 0;

		for (int dir = 0; dir < 4; dir++) {
			if (flag == 1) break;

			for (int j = 0; j < N; j++) {
				if (flag == 1) break;
			
				for (int k = 0; k < M; k++) {
					if (flag == 1) break;
					placeSticker(j, k, dir);
				}
			}
		}
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) res++;
		}
	}

	cout << res;

	return 0;
}