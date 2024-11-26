#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int y;
	int x;
};

int T, h, w;
char board[100][100];
int vis[100][100];
vector<Node>door[26];
int dat[26];
int res;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	queue<Node>tmp;
	queue<Node>q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i != 0 && i != h - 1 && j != 0 && j != w - 1) continue;

			if (board[i][j] == '*') continue;

			if (board[i][j] == '.') {
				q.push({ i,j });
				vis[i][j] = 1;
			}
			else if (board[i][j] == '$') {
				res++;
				q.push({ i,j });
				vis[i][j] = 1;
			}
			else if (board[i][j] >= 'a' && board[i][j] <= 'z') {
				dat[board[i][j] - 'a'] = 1;
				q.push({ i,j });
				vis[i][j] = 1;
			}
			else if (board[i][j] >= 'A' && board[i][j] <= 'Z') { // 대문자
				tmp.push({ i,j });
			}
		}
	}

	while (!tmp.empty()) { // 대문자들 확인
		Node now = tmp.front();
		tmp.pop();

		if (dat[board[now.y][now.x] - 'A'] == 1) {
			q.push(now);
			vis[now.y][now.x] = 1;
		}
	}

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (vis[ny][nx] == 1) continue;
			if (board[ny][nx] == '*') continue;

			if (board[ny][nx] == '$') res++;
			else if (board[ny][nx] >= 'a' && board[ny][nx] <= 'z') {
				dat[board[ny][nx] - 'a'] = 1;
				
				// 다른 문 확인
				for (int j = 0; j < door[board[ny][nx] - 'a'].size(); j++) {
					Node check = door[board[ny][nx] - 'a'][j];

					for (int dir = 0; dir < 4; dir++) {
						int cy = check.y + dy[dir];
						int cx = check.x + dx[dir];

						if ((cy < 0 || cy >= h || cx < 0 || cx >= w) || vis[cy][cx] == 1) {
							q.push(check);
							vis[check.y][check.x] = 1;
							break;
						}
					}
				}
			}
			else if (board[ny][nx] >= 'A' && board[ny][nx] <= 'Z') {
				if (dat[board[ny][nx] - 'A'] == 0) continue;
			}

			vis[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		// init
		for (int i = 0; i < 26; i++) door[i].clear();
		for (int i = 0; i < 26; i++) dat[i] = 0;
		memset(vis, 0, sizeof(vis));
		res = 0;

		// input
		cin >> h >> w;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];

				if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
					door[board[i][j] - 'A'].push_back({ i,j });
				}
			}
		}

		string input;
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '0') break;
			dat[input[i] - 'a']++;
		}


		// solve
		bfs();

		cout << res << "\n";
	}

	return 0;
}