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

struct Node {
	int y;
	int x;
};

int N;
int res = 1;
int arr[100][100];
int vis[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int sy, int sx, int lev) {
	queue<Node>q;
	q.push({ sy, sx });
	vis[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (vis[ny][nx] == 1 || arr[ny][nx] <= lev) continue;

			q.push({ ny, nx });
			vis[ny][nx] = 1;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	for (int lev = 1;lev <= 100;lev++) {
		int cnt = 0;
		memset(vis, 0, sizeof(vis));

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (arr[i][j] > lev && vis[i][j] == 0) {
					cnt++;
					bfs(i, j, lev);
				}
			}
		}
		res = max(res, cnt);
	}

	cout << res;

	return 0;
}