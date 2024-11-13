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
	int k;
};

int N, M, K;
int res, flag;
int arr[1001][1001];
int vis[1001][1001][11];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	// init
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			for (int k = 0;k <= K;k++) {
				vis[i][j][k] = 21e8;
			}
		}
	}

	queue<Node>q;
	q.push({ 1,1,0 });
	vis[1][1][0] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M) continue;

			if (arr[ny][nx] == 0) { // 이동 가능
				if (vis[ny][nx][now.k] <= vis[now.y][now.x][now.k] + 1) continue;

				vis[ny][nx][now.k] = vis[now.y][now.x][now.k] + 1;
				q.push({ ny,nx,now.k });
			}
			else { // 벽
				if (now.k == K) continue;
				if (vis[ny][nx][now.k + 1] <= vis[now.y][now.x][now.k] + 1) continue;

				vis[ny][nx][now.k + 1] = vis[now.y][now.x][now.k] + 1;
				q.push({ ny,nx,now.k + 1 });
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 1;i <= N;i++) {
		string str;
		cin >> str;

		for (int j = 1;j <= M;j++) {
			arr[i][j] = str[j - 1] - '0';
		}
	}

	if (N == 1 && M == 1) {
		cout << "1";
		return 0;
	}
	
	bfs();

	int res = 21e8;
	for (int i = 0;i <= K;i++) res = min(res, vis[N][M][i]);

	if (res == 21e8) cout << "-1";
	else cout << res;

	return 0;
}