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
long long dp[91];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);
	
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2;i <= N;i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N];

	return 0;
}