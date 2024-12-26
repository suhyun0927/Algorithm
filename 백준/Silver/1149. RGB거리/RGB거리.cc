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
int r, g, b;
int dp[1001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);
	
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> r >> g >> b;

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
	}

	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));

	return 0;
}