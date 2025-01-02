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
int arr[1000];
int dp[1000];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) cin >> arr[i];

	
	for (int i = 0;i < N;i++) {
		dp[i] = arr[i];
		for (int j = 0;j < N;j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
		}
		res = max(res, dp[i]);
	}

	cout << res;

	return 0;
}