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

char arr[5][5];
int vis[5][5]; // 넣었는지 여부
Node flag[7]; // 레벨따라 값 넣어놓을거
int res; // 경우의 수
int s; // 이다솜파 확인

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool checkAdj() {
	int check[7] = { 0 };

	queue<Node>q;
	q.push(flag[0]);
	check[0] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (vis[ny][nx] == 0) continue;
			if (check[vis[ny][nx]-1] == 1) continue;

			check[vis[ny][nx]-1] = 1;
			q.push({ ny,nx });
		}
	}

	for (int i = 0;i < 7;i++) if (check[i] == 0) return false;
	return true;
}

void run(int sy, int sx, int level) {
	if (level == 7) {
		if (s < 4) return;
		if (!checkAdj()) return;
		res++;
		return;
	}

	for (int i = sy;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (i == sy && j < sx) continue;
			if (vis[i][j] != 0) continue;

			if (arr[i][j] == 'S') s++;
			vis[i][j] = level + 1;
			flag[level] = { i,j };
			run(i, j, level + 1);
			if (arr[i][j] == 'S') s--;
			vis[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0;i < 5;i++) {
		string input;
		cin >> input;

		for (int j = 0;j < 5;j++) arr[i][j] = input[j];
	}

	run(0,0,0);

	cout << res;

	return 0;
}