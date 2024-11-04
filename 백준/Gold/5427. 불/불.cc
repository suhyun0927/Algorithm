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

int arr[1001][1001];
int person[1001][1001];
int fire[1001][1001];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int T, n, m;
Node sp, sf;

queue<Node>q;
queue<Node>f;
void bfs_person() {
	// init
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			person[i][j] = 21e8;
		}
	}

	q.push({ sp.y, sp.x });
	person[sp.y][sp.x] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (arr[ny][nx] == -1) continue;
			if (person[ny][nx] <= person[now.y][now.x] + 1) continue;

			person[ny][nx] = person[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

void bfs_fire() {
	while (!f.empty()) {
		Node now = f.front();
		f.pop();

		for (int i = 0;i < 4;i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (arr[ny][nx] == -1) continue;
			if (fire[ny][nx] <= fire[now.y][now.x] + 1) continue;

			fire[ny][nx] = fire[now.y][now.x] + 1;
			f.push({ ny,nx });
		}
	}
}

int main() {
	cin >> T;

	for (int tc = 1;tc <= T;tc++) {
		cin >> m >> n;

		// init
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				fire[i][j] = 21e8;
			}
		}

		// input
		for (int i = 0;i < n;i++) {
			string str;
			cin >> str;

			for (int j = 0;j < m;j++) {
				if (str[j] == '#') {
					arr[i][j] = -1;
				}
				else if (str[j] == '.') arr[i][j] = 0;
				else if (str[j] == '@') {
					sp = { i,j };
				}
				else { // str[j] == 'F'
					f.push({ i,j });
					fire[i][j] = 0;
				}
			}
		}

		// 탐색
		bfs_person();
		bfs_fire();

		int res = 21e8;
		// 비교
		
		for (int i = 0;i < n;i++) {
			if (i != 0 && i != n - 1) {
				if (fire[i][0] > person[i][0]) res = min(res, person[i][0]);
				if (fire[i][m-1] > person[i][m-1]) res = min(res, person[i][m-1]);

				continue;
			}

			for (int j = 0;j < m;j++) {
				if (fire[i][j] > person[i][j]) res = min(res, person[i][j]);
			}
		}

		if (res == 21e8) cout << "IMPOSSIBLE\n";
		else cout << res + 1 << "\n";
	}

	return 0;
}