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
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2;i <= N;i++) {
		for (int j = 2;j <= K;j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}

	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % 1000000003;

	return 0;
}