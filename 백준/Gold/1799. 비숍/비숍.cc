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

int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0,0,-1,1 };

int N;
int arr[10][10]; // 체스판
vector<Node>place[2]; // 놓을 수 있는 칸
int checkL[19]; // 역슬래쉬\ 방향 (x-y)
int checkR[19]; // 슬래쉬/ 방향 (x+y)
int res[2];

void run(int index, int level, int color) {
	res[color] = max(res[color], level);

	for (int i = index;i < place[color].size();i++) {
		Node now = place[color][i];
		if (checkL[now.x - now.y + (N - 1)] == 1) continue;
		if (checkR[now.x + now.y] == 1) continue;

		checkL[now.x - now.y + (N - 1)] = 1;
		checkR[now.x + now.y] = 1;
		run(i + 1, level + 1, color);
		checkL[now.x - now.y + (N - 1)] = 0 ;
		checkR[now.x + now.y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1 && ((i%2==0 && j%2==0) || (i % 2 == 1 && j % 2 == 1))) place[0].push_back({ i,j });
			else if (arr[i][j] == 1) place[1].push_back({ i,j });
		}
	}
	
	run(0, 0, 0);
	run(0, 0, 1);

	cout << res[0] + res[1];

	return 0;
}