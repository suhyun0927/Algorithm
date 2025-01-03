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
long long dp[101];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 5;i <= 100;i++) dp[i] = dp[i - 1] + dp[i - 5];

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> res;
		cout << dp[res] << "\n";
	}

	return 0;
}