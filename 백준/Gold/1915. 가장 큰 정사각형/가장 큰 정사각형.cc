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

int N, M;
int arr[1001][1001];
int dp[1001][1001];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		string input;
		cin >> input;
		for (int j = 1;j <= M;j++) arr[i][j] = input[j - 1] - '0';
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j] == 0) continue;

			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans;

	return 0;
}