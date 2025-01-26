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
long long dp[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dp[2] = 3;
	
	for (int i = 4;i <= N;i += 2) {
		for (int j = i - 2;j >= 2;j -= 2) {
			if (j == i - 2) dp[i] += dp[j] * 3;
			else dp[i] += dp[j] * 2;
		}
		dp[i] += 2;
	}

	cout << dp[N];

	return 0;
}