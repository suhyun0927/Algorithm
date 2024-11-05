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
	int prev;
	int x;
	int sec;

	bool operator<(Node r) const {
		return sec > r.sec;
	}
};

int N, K;
Node arr[100001];
int dx[2] = { -1,1 };

void bfs() {
	// init
	for (int i = 0;i < 100001;i++) {
		arr[i].sec = 21e8;
	}

	priority_queue<Node>q;
	arr[N] = { -1, N, 0 };
	q.push({-1,N, 0});

	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		for (int i = 0;i < 3;i++) {
			int nx;

			if (i == 2) nx = now.x * 2;
			else nx = now.x + dx[i];

			if (nx == K) {
				arr[nx] = { now.x, nx, now.sec + 1 };
				return;
			}

			if (nx < 0 || nx >= 100001) continue;
			if (arr[nx].sec <= now.sec + 1) continue;
			if (nx > K + 1) continue;

			arr[nx] = { now.x, nx, now.sec + 1 };
			q.push(arr[nx]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N >> K;

	if (N > K) {
		cout << N - K << "\n";

		for (int i = N;i >= K;i--) cout << i << " ";

		return 0;
	}

	bfs();

	stack<int>st;
	int now = K;

	while (now != N) {
		st.push(arr[now].prev);
		now = arr[now].prev;
	}

	cout << st.size() << "\n";

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << K << " ";

	return 0;
}