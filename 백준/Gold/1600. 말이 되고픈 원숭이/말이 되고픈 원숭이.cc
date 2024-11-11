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

struct Dist {
	int y;
	int x;
	int horse;
	int cnt;
};

int K, W, H;
int res = 1;
int arr[201][201];
int vis[201][201][31];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int hy[8] = { -1,-2,-2,-1,1,2,2,1 };
int hx[8] = { -2,-1,1,2,2,1,-1,-2 };

void bfs() {
	for (int i = 0;i < H;i++) {
		for (int j = 0;j < W;j++) {
			for (int k = 0;k <= K;k++) {
				vis[i][j][k] = 21e7;
			}
		}
	}

	queue<Dist>q;
	q.push({ 0,0,0,0 });
	vis[0][0][0] = 0;

	while (!q.empty()) {
		Dist now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (arr[ny][nx] == 1) continue; // 장애물
			if (vis[ny][nx][now.horse] <= vis[now.y][now.x][now.horse] + 1 ) continue;

			vis[ny][nx][now.horse] = vis[now.y][now.x][now.horse] + 1;
			q.push({ ny, nx, now.horse, now.cnt + 1 });
		}

		if (now.horse == K) continue;

		for (int i = 0;i < 8;i++) {
			int ny = now.y + hy[i];
			int nx = now.x + hx[i];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (arr[ny][nx] == 1) continue; // 장애물
			if (vis[ny][nx][now.horse+1] <= vis[now.y][now.x][now.horse] + 1) continue;

			vis[ny][nx][now.horse + 1] = vis[now.y][now.x][now.horse] + 1;
			q.push({ ny, nx, now.horse+1, now.cnt + 1 });
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K >> W >> H;

	for (int i = 0;i < H;i++) {
		for (int j = 0;j < W;j++) {
			cin >> arr[i][j];
		}
	}

	bfs();

	int res = 21e7;
	
	for (int i = 0;i <= K;i++) {
		res = min(res, vis[H - 1][W - 1][i]);
	}

	if (res == 21e7) cout << "-1";
	else cout << res;

	return 0;
}