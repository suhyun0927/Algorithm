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

int N, K;
int coin[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) cin >> coin[i];
	for (int i = 1; i <= K; i++) dp[i] = 1000000;
	for (int i = 1;i <= N;i++) {
		for (int j = coin[i];j <= K;j++) dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	}
	
	if (dp[K] == 1000000) cout << -1;
	else cout << dp[K];

	return 0;
}