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

int arr[100001];
int n, k;
int Max;
queue<int>q;

int main() {
	// input
	cin >> n >> k;
	Max = abs(k - n);

	// init
	for (int i = 0;i < 100001;i++) arr[i] = 21e8;

	// bfs
	arr[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		// 걷기
		int next;
		for (int i = 0;i < 3;i++) {
			if (i == 2) {
				next = now * 2;

				if (next < 0 || next >= 100001) continue;
				if (arr[next] <= arr[now]) continue;
				if (arr[now] + 1 > Max) continue;

				arr[next] = arr[now];
				q.push(next);
			}
			else {
				if (i == 0) next = now + 1;
				if (i == 1) next = now - 1;

				if (next < 0 || next >= 100001) continue;
				if (arr[next] <= arr[now] + 1) continue;
				if (arr[now] + 1 > Max) continue;

				arr[next] = arr[now] + 1;
				q.push(next);
			}
		}
	}

	cout << arr[k];

	return 0;
}