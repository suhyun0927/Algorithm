#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
using namespace std;

struct Node {
	int y;
	int x;
};

struct Time {
	int y;
	int x;
	int t;
};

int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M, G, R;
int land[50][50]; // 그냥 땅
int vis[50][50]; // 약 뿌렸나 안뿌렸나
int vis_green[50][50];
int vis_red[50][50];
int total_map[50][50];
int ans;
vector<Node>canUse;
vector<int>green, red;

void bfs() {
	// clear
	memset(vis_green, 0, sizeof(vis_green));
	memset(vis_red, 0, sizeof(vis_red));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			total_map[i][j] = land[i][j];
		}
	}

	queue<Time>g;
	queue<Time>r;

	for (int i = 0;i < G;i++) {
		int now = green[i];
		total_map[canUse[now].y][canUse[now].x] = 3;
		vis_green[canUse[now].y][canUse[now].x] = 1;
		g.push({ canUse[now].y, canUse[now].x, 1 });
	}
	for (int i = 0;i < R;i++) {
		int now = red[i];
		total_map[canUse[now].y][canUse[now].x] = 4;
		vis_red[canUse[now].y][canUse[now].x] = 1;
		r.push({ canUse[now].y, canUse[now].x, 1 });
	}

	while (!g.empty() || !r.empty()) {
		int Gsize = g.size();
		
		for (int i = 0;i < Gsize;i++) {
			Time now = g.front();
			g.pop();
			if (total_map[now.y][now.x] == -1) continue;
			for (int j = 0;j < 4;j++) {
				int ny = now.y + dy[j];
				int nx = now.x + dx[j];
				 
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

				if (vis_green[ny][nx] == 0 && (total_map[ny][nx] == 1 || total_map[ny][nx] == 2)) {
					vis_green[ny][nx] = now.t + 1;
					g.push({ ny,nx,now.t + 1 });
					total_map[ny][nx] = 3;
				}
			}
		}
		
		int Rsize = r.size();

		for (int i = 0;i < Rsize;i++) {
			Time now = r.front();
			r.pop();
			if (total_map[now.y][now.x] == -1) continue;
			for (int j = 0;j < 4;j++) {
				int ny = now.y + dy[j];
				int nx = now.x + dx[j];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

				if (vis_red[ny][nx] == 0 && (total_map[ny][nx] == 1 || total_map[ny][nx] == 2)) {
					vis_red[ny][nx] = now.t + 1;
					r.push({ ny,nx,now.t + 1 });
					total_map[ny][nx] = 4;
				}
				else if (vis_red[ny][nx] == 0 && total_map[ny][nx] == 3) {
					if (vis_green[ny][nx] == now.t + 1) {
						total_map[ny][nx] = -1;
						vis_red[ny][nx] = now.t + 1;
					}
				}
			}
		}
	}

	int flower = 0;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (total_map[i][j] == -1) flower++;
		}
	}

	ans = max(ans, flower);
}

void chooseR(int index, int level) {
	if (level == R) {
		bfs();
		return;
	}

	for (int i = index;i < canUse.size();i++) {
		if (vis[canUse[i].y][canUse[i].x] == 1) continue;

		vis[canUse[i].y][canUse[i].x] = 1;
		red.push_back(i);
		chooseR(i + 1, level + 1);
		vis[canUse[i].y][canUse[i].x] = 0;
		red.pop_back();
	}
}

void chooseG(int index, int level) {
	if (level == G) {
		chooseR(0, 0);
		return;
	}

	for (int i = index;i < canUse.size();i++) {
		if (vis[canUse[i].y][canUse[i].x] == 1) continue;

		vis[canUse[i].y][canUse[i].x] = 1;
		green.push_back(i);
		chooseG(i + 1, level + 1);
		vis[canUse[i].y][canUse[i].x] = 0;
		green.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> land[i][j];

			if (land[i][j] == 2) canUse.push_back({ i,j });
		}
	}

	chooseG(0, 0);

	cout << ans;

	return 0;
}