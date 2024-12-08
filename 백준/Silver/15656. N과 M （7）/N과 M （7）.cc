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
vector<int>v;
int flag[9]; // 레벨따라 값 넣어놓을거
//int vis[9]; // 넣었는지 여부

void run(int level) {
	if (level == M) {
		for (int i = 0;i < M;i++) cout << v[flag[i]] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0;i < N;i++) {
		//if (vis[i] == 1) continue;
		//if (level != 0 && flag[level - 1] > i) continue;

		flag[level] = i;
		//vis[i] = 1;
		run(level + 1);
		//vis[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	sort(v.begin(), v.end());

	run(0);
}