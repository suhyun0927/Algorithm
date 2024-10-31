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

int arr[101][101];
int dist[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;

queue<Node>q;
void bfs() {
	// init
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dist[i][j] = 21e8;
		}
	}

	q.push({ 1, 1 });
	dist[1][1] = 1;
	
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m) continue;
			if (arr[ny][nx] == 0) continue;
			if (dist[ny][nx] <= dist[now.y][now.x] + 1) continue;

			dist[ny][nx] = dist[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> n >> m;
	
	// input
	for (int i = 1;i <= n;i++) {
		string str;
		cin >> str;

		for (int j = 1;j <= m;j++) {
			arr[i][j] = str[j-1] - '0';
		}
	}

	bfs();

	cout << dist[n][m];

	return 0;
}