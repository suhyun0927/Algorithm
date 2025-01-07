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
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3;i <= N;i++) dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);

	if (dp[N] % 2 == 0) cout << "CY";
	else cout << "SK";

	return 0;
}