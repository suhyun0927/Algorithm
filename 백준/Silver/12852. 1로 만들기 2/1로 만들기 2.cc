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

int go(int n) {
	if (dp[n] != -1) return dp[n];

	dp[n] = go(n - 1) + 1;

	if (n % 3 == 0) dp[n] = min(dp[n], go(n / 3) + 1);

	if (n % 2 == 0) dp[n] = min(dp[n], go(n / 2) + 1);

	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> X;

	// init
	for (int i = 0; i <= X; i++) dp[i] = -1;
	dp[1] = 0;

	cout << go(X) << "\n";

	while (X != 0) {
		cout << X << " ";

		if (dp[X] == dp[X - 1] + 1) X--;
		else if (X % 2 == 0 && dp[X] == dp[X / 2] + 1) X /= 2;
		else if (X % 3 == 0 && dp[X] == dp[X / 3] + 1) X /= 3;
	}

	return 0;
}