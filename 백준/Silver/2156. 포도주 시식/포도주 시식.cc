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
int arr[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1;i <= N;i++) cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++){
		dp[i] = max(max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]), dp[i-1]);
	}

	cout << dp[N];

	return 0;
}