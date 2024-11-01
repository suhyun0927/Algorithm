#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

struct Node {
	int z;
	int y;
	int x;
};

int m, n, h;
int arr[100][100][100];
int dist[100][100][100];
int leave = 0;
int Max = 0;
queue<Node>q;

int dz[6] = { -1, 1, 0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dx[6] = { 0,0,0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = now.z + dz[i];
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (arr[nz][ny][nx] != 0) continue;
			if (dist[nz][ny][nx] <= dist[now.z][now.y][now.x] + 1) continue;

			dist[nz][ny][nx] = dist[now.z][now.y][now.x] + 1;
			q.push({ nz,ny,nx });
		}
	}
}

int main() {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				// init
				dist[i][j][k] = 21e8;

				// input
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 0) leave++;
				else if (arr[i][j][k] == 1) {
					q.push({ i,j,k });
					dist[i][j][k] = 0;
				}
			}
		}
	}

	if (leave == 0) {
		cout << "0";
		return 0;
	}

	bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				// 익어야 할 토마토 였음
				if (arr[i][j][k] == 0) {
					// 안익은 경우
					if (dist[i][j][k] == 21e8) {
						cout << "-1";
						return  0;
					}

					// 익은 경우
					Max = max(Max, dist[i][j][k]);
				}
			}
		}
	}

	cout << Max;

	return 0;
} 