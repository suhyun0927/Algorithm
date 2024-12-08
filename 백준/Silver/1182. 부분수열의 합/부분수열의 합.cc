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

int N, S;
int arr[20]; // input
int vis[20];
int sum, res, flag;

void run(int level) {
	if (level == N) {
		sum = 0;
		flag = 0;
		for (int i = 0;i < N;i++) {
			if (vis[i] == 0) continue;
			sum += arr[i];
			flag = 1;
		}
		if (sum == S && flag == 1) {
			int de = -1;
			res++;
		}
		return;
	}

	vis[level] = 0;
	run(level + 1);
	vis[level] = 1;
	run(level + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0;i < N;i++) cin >> arr[i];

	run(0);

	cout << res;
}
