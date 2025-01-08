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

int N, flag = 1;
int dp[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	if (N == 0) flag = 0;
	if (N < 0) {
		N *= -1;
		if (N % 2 == 0) flag = -1;
	}

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2;i <= N;i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;

	cout << flag << "\n" << abs(dp[N]);

	return 0;
}