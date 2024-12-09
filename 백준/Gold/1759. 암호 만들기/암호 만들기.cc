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

int L, C;
char arr[15];
int vow; // 모음 개수
int flag[15]; // 레벨따라 값 넣어놓을거
int vis[15]; // 넣었는지 여부

void run(int level) {
	if (level == L) {
		if (vow == 0 || L - vow < 2) return;
		for (int i = 0;i < L;i++) cout << arr[flag[i]];
		cout << "\n";
		return;
	}

	for (int i = 0;i < C;i++) {
		if (vis[i] == 1) continue;
		if (level != 0 && flag[level - 1] > i) continue;

		int is_vow = 0;
		if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'e' || arr[i] == 'o') is_vow = 1;
		
		if (is_vow == 1) vow++;
		flag[level] = i;
		vis[i] = 1;
		run(level + 1);
		vis[i] = 0;
		if (is_vow == 1) vow--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;

	for (int i = 0;i < C;i++) cin >> arr[i];
		
	sort(arr, arr + C);

	run(0);

	return 0;
}