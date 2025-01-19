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

int T, N;
int arr[2][100001];
int dp[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int tc = 1;tc <= T;tc++) {
		cin >> N;

		for (int i = 0;i < 2;i++) {
			for (int j = 1;j <= N;j++) {
				cin >> arr[i][j];
			}
		}

		memset(dp, 0, sizeof(dp));

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2;i <= N;i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << max(dp[0][N], dp[1][N]) << "\n";
	}

	return 0;
}