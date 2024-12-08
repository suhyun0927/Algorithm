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

int N, M;
int flag[9]; // 레벨따라 값 넣어놓을거

void run(int level) {
	if (level == M) {
		for (int i = 0;i < M;i++) cout << flag[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1;i <= N;i++) {
		flag[level] = i;
		run(level + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	run(0);
}