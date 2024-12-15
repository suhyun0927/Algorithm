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

struct Node {
	int y;
	int x;
};

int N;
int arr[101][101];
vector<int>dragon[20]; // 방향 저장
Node locate[20];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void run(int num, int goal) {
	for (int i = 0;i <= goal;i++) {
		if (i == 0) {
			int ny = locate[num].y + dy[dragon[num][0]];
			int nx = locate[num].x + dx[dragon[num][0]];

			if (ny < 0 || ny>100 || nx < 0 || nx>100) return;

			arr[ny][nx] = 1;
			locate[num] = { ny, nx };
		}
		else {
			for (int j = dragon[num].size() - 1;j >= 0;j--) {
				int dir = (dragon[num][j] + 1) % 4;
				int ny = locate[num].y + dy[dir];
				int nx = locate[num].x + dx[dir];

				if (ny < 0 || ny>100 || nx < 0 || nx>100) return;

				arr[ny][nx] = 1;
				locate[num] = { ny, nx };
				dragon[num].push_back(dir);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		locate[i] = { y,x };
		arr[y][x] = 1;
		dragon[i].push_back(d);

		run(i, g);
	}

	int res = 0;

	for (int i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1) res++;
		}
	}

	cout << res;

	return 0;
}