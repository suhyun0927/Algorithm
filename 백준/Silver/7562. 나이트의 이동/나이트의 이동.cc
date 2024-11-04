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

int T, I;
Node start, fin;
int arr[300][300];
int dy[8] = { -1,-2, -2, -1,1,2,2,1 };
int dx[8] = { -2,-1,1,2,-2,-1,1,2 };

void bfs() {
	// init
	for (int i = 0;i < I;i++) {
		for (int j = 0;j < I;j++) {
			arr[i][j] = 21e8;
		}
	}

	queue<Node>q;
	q.push({ start.y, start.x });
	arr[start.y][start.x] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 8;i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (ny < 0 || ny >= I || nx < 0 || nx >= I) continue;
			if (arr[ny][nx] <= arr[now.y][now.x] + 1) continue;

			arr[ny][nx] = arr[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> T;

	for (int tc = 1;tc <= T;tc++) {
		// input
		cin >> I;
		cin >> start.y >> start.x;
		cin >> fin.y >> fin.x;

		// 탐색
		bfs();

		cout << arr[fin.y][fin.x] << "\n";
	}

	return 0;
}