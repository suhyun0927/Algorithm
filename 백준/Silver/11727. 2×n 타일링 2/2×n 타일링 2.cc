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

int X;
int dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> X;

	// init
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3;i <= X;i++) dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

	cout << dp[X];

	return 0;
}