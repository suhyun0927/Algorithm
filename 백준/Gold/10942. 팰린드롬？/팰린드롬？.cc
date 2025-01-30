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

int n, m, s, e;
int arr[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1;i <= n;i++) cin >> arr[i];
	
	for (int i = 1;i <= n;i++) {
		dp[i][i] = 1;
		if (i != n && arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = n-1;i >= 1;i--) {
		for (int j = i + 2;j <= n;j++) {
			if (arr[i] != arr[j]) continue;
			if (dp[i + 1][j - 1] == 0) continue;

			dp[i][j] = 1;
		}
	}

	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}

	return 0;
}