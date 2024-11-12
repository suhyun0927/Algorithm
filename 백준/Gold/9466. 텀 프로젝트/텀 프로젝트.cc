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
	int y;
	int x;
};

int T, n;
int res, flag;
int arr[100001];
int vis[100001];
int fin[100001];

void dfs(int now) {
	vis[now] = 1;

	if (vis[arr[now]] == 0) dfs(arr[now]);
	else if(fin[arr[now]] == 0){
		for (int i = arr[now];i != now;i = arr[i]) res++;
		res++;
	}

	fin[now] = 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int tc = 1;tc <= T;tc++) {
		// init
		memset(vis, 0, sizeof(vis));
		memset(fin, 0, sizeof(fin));
		
		// input
		cin >> n;
		res = 0;

		for (int i = 1;i <= n;i++) cin >> arr[i];

		for (int i = 1;i <= n;i++) {
			if (vis[i] == 1) continue;
			dfs(i);
		}

		cout << n - res << "\n";
	}
	

	return 0;
}