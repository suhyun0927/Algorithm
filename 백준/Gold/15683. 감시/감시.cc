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
#include <map>
using namespace std;

struct Node {
	int y;
	int x;
};

struct Check {
	int y;
	int x;
	int dir;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M, cnt;
int arr[8][8]; // 사무실 맵
int copy_arr[8][8];
vector<Node>cctv;
int cnt_dir[6] = { 0,4,2,4,4,1 }; // cctv 번호별 가짓수
vector<string>cctv_dir[6];
int now_num[9]; // 현재 선택한 cctv 방향
int res = 21e8;

void check_cctv_cnt() {
	//init
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}

	for (int i = 0;i < cnt;i++) { // cctv 돌기
		Node now = cctv[i]; // 현재 cctv 인덱스
		int cctv_num = arr[now.y][now.x]; // cctv 번호 확인
		string dir_index = cctv_dir[cctv_num][now_num[i]]; // 이번에 확인할 방향 list

		// 한 방향 bfs
		queue<Check>q;

		for (int j = 0;j < dir_index.length();j++) {
			int now_dir = dir_index[j] - '0';
			q.push({ now.y, now.x, now_dir });
		}

		while (!q.empty()) {
			Check nnow = q.front();
			q.pop();

			int ny = nnow.y + dy[nnow.dir];
			int nx = nnow.x + dx[nnow.dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (copy_arr[ny][nx] == 6) continue;

			q.push({ ny,nx,nnow.dir });
			if(copy_arr[ny][nx] == 0) copy_arr[ny][nx] = 7;
		}
	}

	int detect = 0;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (copy_arr[i][j] == 0) detect++;
		}
	}

	res = min(res, detect);
}

void run(int level) {
	if (level == cnt) {
		check_cctv_cnt();
		return;
	}

	Node now = cctv[level];

	int tmp = cnt_dir[arr[now.y][now.x]];

	for (int i = 0;i < tmp;i++) {
		now_num[level] = i;
		run(level + 1);
	}
}

void save_cctv_dir() {
	cctv_dir[1].push_back({ "0" });
	cctv_dir[1].push_back({ "1" });
	cctv_dir[1].push_back({ "2" });
	cctv_dir[1].push_back({ "3" });

	cctv_dir[2].push_back({ "01" });
	cctv_dir[2].push_back({ "23" });

	cctv_dir[3].push_back({ "02" });
	cctv_dir[3].push_back({ "03" });
	cctv_dir[3].push_back({ "12" });
	cctv_dir[3].push_back({ "13" });

	cctv_dir[4].push_back({ "012" });
	cctv_dir[4].push_back({ "013" });
	cctv_dir[4].push_back({ "023" });
	cctv_dir[4].push_back({ "123" });

	cctv_dir[5].push_back({ "0123" });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ i,j });
				cnt++; // cctv 개수
			}
		}
	}

	// cctv 방향 저장
	save_cctv_dir();

	run(0);

	cout << res;

	return 0;
}