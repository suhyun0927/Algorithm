#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int arr[51][51];
int Max = 0;

struct Node {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, k;
int cnt = 0;

queue<Node>q;
void bfs(int sy, int sx) {
	int area = 1;
	q.push({ sy, sx });
	arr[sy][sx] = 2;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (arr[ny][nx] != 1) continue;

			// 1일때
			arr[ny][nx] = 2;
			area++;
			q.push({ ny,nx });
		}
	}

	Max = max(Max, area);
}

int main() {
	int t;
	cin >> t;

	for (int tc = 0;tc < t;tc++) {
		// init
		memset(arr, 0, sizeof(arr));
		cnt = 0;

		// input
		cin >> n >> m >> k;

		for (int i = 0;i < k;i++) {
			int y, x;
			cin >> y >> x;
			arr[y][x] = 1;
		}

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (arr[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}


	return 0;
}