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

struct Node{
	int y;
	int x;
};

int M, N, K;
int arr[100][100];
int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0,0,-1,1 };

priority_queue<int, vector<int>, greater<int>>pq;

void bfs(int sy, int sx) {
	queue<Node>q;
	int cnt = 1;
	arr[sy][sx] = 1;
	q.push({ sy,sx });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
			if (arr[ny][nx] == 1) continue;

			arr[ny][nx] = 1;
			q.push({ ny,nx });
			cnt++;
		}
	}

	pq.push(cnt);
}

int main() {
	cin >> M >> N >> K;

	for (int i = 0;i < K;i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		for (int j = sy;j < ey;j++) {
			for (int k = sx;k < ex;k++) {
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j] == 1) continue;
			bfs(i,j);
		}
	}

	cout << pq.size() << "\n";

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}