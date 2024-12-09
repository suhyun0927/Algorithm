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

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Node {
	int S;
	int W;
};

int N;
Node arr[8];
int vis[8]; // 깨졌는지 여부
int Max = 0;

Node flag[7]; // 레벨따라 값 넣어놓을거
int res; // 경우의 수
int s; // 이다솜파 확인

void run(int now) {
	if (now == N) {
		int tmp = 0;
		for (int i = 0;i < N;i++) {
			if (vis[i] == 1) tmp++;
		}

		Max = max(tmp, Max);
		return;
	}

	if (vis[now] == 1) {
		run(now + 1);
		return;
	}

	int cnt = 0;
	for (int i = 0;i < N;i++) {
		if (vis[i] == 1) continue;
		if (i == now) continue;

		arr[now].S -= arr[i].W;
		arr[i].S -= arr[now].W;
		if (arr[now].S <= 0) vis[now] = 1;
		if (arr[i].S <= 0) vis[i] = 1;

		run(now + 1);
		
		arr[now].S += arr[i].W;
		arr[i].S += arr[now].W;
		if (arr[now].S > 0) vis[now] = 0;
		if (arr[i].S > 0) vis[i] = 0;

		cnt++;
	}

	if(cnt ==0) run(now + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) cin >> arr[i].S >> arr[i].W;

	run(0);

	cout << Max;

	return 0;
}