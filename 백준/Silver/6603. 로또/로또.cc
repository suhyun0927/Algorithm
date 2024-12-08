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

int N;
int arr[13];
int flag[6]; // 레벨따라 값 넣어놓을거
int vis[50]; // 넣었는지 여부
int dat[50];

void run(int level) {
	if (level == 6) {
		for (int i = 0;i < 6;i++) cout << arr[flag[i]] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0;i < N;i++) {
		if (vis[i] == 1) continue;
		if (level != 0 && flag[level - 1] > i) continue;

		flag[level] = i;
		vis[i] = 1;
		run(level + 1);
		vis[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> N;

		if (N == 0) return 0;

		memset(dat, 0, sizeof(dat));
		for (int i = 0;i < N;i++) {
			int input;
			cin >> input;

			if (dat[input] == 1) continue;

			dat[input]++;
			arr[i] = input;
		}
		
		run(0);
		cout << "\n";
	}

	return 0;
}