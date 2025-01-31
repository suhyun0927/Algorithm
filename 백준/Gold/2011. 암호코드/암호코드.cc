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

string input;
int arr[5001];
int dp[5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> input;

	for (int i = 1;i <= input.length();i++) arr[i] = input[i - 1] - '0';

	if (input.length() == 1 && arr[1] == 0) {
		cout << 0;
		return 0;
	}

	dp[0] = 1;

	for (int i = 1;i <= input.length();i++) {
		if (arr[i] >= 1 && arr[i] <= 9) dp[i] = dp[i - 1] % 1000000;

		if (i == 1) continue;

		int tmp = arr[i] + arr[i - 1] * 10;
		if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2] % 1000000;
	}

	cout << dp[input.length()] % 1000000;

	return 0;
}