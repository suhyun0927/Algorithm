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
int t[16];
int p[16];
int dp[16];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) cin >> t[i] >> p[i];

	int end;
	for (int i = N;i > 0;i--) {
		end = i + t[i];

		if (end > N + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], dp[end] + p[i]);
	}

	cout << dp[1];

	return 0;
}