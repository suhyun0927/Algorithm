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

int N, M, P;
int step[10];
int castle[10];
int board[1001][1001];
vector<Node>pos[10];
int dy[4] = { -1, 1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	cin >> N >> M >> P;

	for (int i = 1;i <= P;i++) cin >> step[i];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char input;
			cin >> input;

			if (input == '.') board[i][j] = 0;
			else if (input == '#') board[i][j] = -1;
			else {
				board[i][j] = input - '0';
				pos[input-'0'].push_back({i,j});
			}
		}
	}

	int fin = 0;

	while (!fin) {
		int totalCnt = 0;
		for (int player = 1;player <= P;player++) {
			for (int i = 0;i < step[player];i++) {
				int stepCnt = 0;
				vector<Node>v;
				for (auto c : pos[player]) {
					for (int dir = 0;dir < 4;dir++) {
						int ny = c.y + dy[dir];
						int nx = c.x + dx[dir];

						if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
						if (board[ny][nx] != 0) continue;
						totalCnt++;
						stepCnt++;
						v.push_back({ ny,nx });
						board[ny][nx] = player;
					}
				}
				if (stepCnt == 0) break;
				pos[player] = v;
			}
		}
		if (totalCnt == 0) fin = 1;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			castle[board[i][j]]++;
		}
	}

	for (int i = 1;i <= P;i++) cout << castle[i] << " ";
}