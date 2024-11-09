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
int area_cnt = 0;
int arr[100][100];
int edge[100][100];
int dist[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int res = 21e8;

void div_area(int sy, int sx) {
	queue<Node>q;
	q.push({ sy,sx });
	arr[sy][sx] = ++area_cnt;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int cnt = 0;

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (arr[ny][nx] == 0) {
				edge[now.y][now.x] = 1;
				continue;
			}
			if (arr[ny][nx] == area_cnt) continue;

			arr[ny][nx] = area_cnt;
			q.push({ ny, nx });
			cnt++;
		}
	}

}

void bfs(int sy, int sx) {
	// init
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			dist[i][j] = 21e8;
		}
	}

	queue<Node>q;
	q.push({ sy,sx});
	dist[sy][sx] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (arr[ny][nx] == arr[sy][sx]) continue;
			if (dist[ny][nx] <= dist[now.y][now.x] + 1)continue;

			if (arr[ny][nx] != 0) {
				res = min(res, dist[now.y][now.x]);
			}
			else {
				dist[ny][nx] = dist[now.y][now.x] + 1;
				q.push({ ny,nx});
			}
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
			if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j] == -1) div_area(i, j);
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j] != 0 && edge[i][j] == 1) bfs(i, j);
		}
	}

	cout << res;

	return 0;
}