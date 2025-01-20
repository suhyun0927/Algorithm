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

int N;
long long dp[10][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < 10;i++) dp[i][0] = 1;

	for (int i = 1;i <= N;i++) {
		for (int j = 0;j < 10;j++) {
			if (j == 0) dp[j][i] = dp[j][i - 1];
			else dp[j][i] = (dp[j][i - 1] + dp[j - 1][i]) % 10007;
		}
	}

	cout << dp[9][N] % 10007;

	return 0;
}