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

int T, N, M;
int coin[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> coin[i];
		cin >> M;

		memset(dp, 0, sizeof(dp));

		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) dp[j] += dp[j - coin[i]];
		}

		cout << dp[M] << '\n';
	}

	return 0;
}