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

int N, M;
int cnt = 0;
int board[101][101];
int on[101][101];
int vis[101][101];
vector<Node>avail[101][101];
int dy[4] = { -1, 1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	queue<Node>q;
	q.push({ 1,1 });
	on[1][1] = 1;
	vis[1][1] = 1;
	cnt++;

	for (int i = 0;i < avail[1][1].size();i++) {
		if (!on[avail[1][1][i].y][avail[1][1][i].x]) {
			on[avail[1][1][i].y][avail[1][1][i].x] = 1;
			cnt++;
		}
	}

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < avail[now.y][now.x].size();i++) {
			Node next = avail[now.y][now.x][i];

			if (on[next.y][next.x] == 1) continue;

			on[next.y][next.x] = 1;
			cnt++;

			for (int j = 0;j < 4;j++) {
				int ny = next.y + dy[j];
				int nx = next.x + dx[j];

				if (ny<1 || ny>N || nx<1 || nx>N) continue;
				if (vis[ny][nx] == 1) {
					q.push({ next.y, next.x });
					vis[next.y][next.x] = 1;
					break;
				}
			}
		}

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny<1 || ny>N || nx<1 || nx>N) continue;
			if (vis[ny][nx] == 1 || on[ny][nx] == 0) continue;
			
			q.push({ ny, nx });
			vis[ny][nx] = 1;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		avail[x][y].push_back({ a,b });
	}

	bfs();

	cout << cnt;

	return 0;
}