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
long long arr[100001][3];
long long dp[100001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int tc = 1;;tc++) {
		cin >> N;
		if (N == 0) return 0;

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < 3;j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][0] = 1000001;
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];

		for (int i = 1;i < N;i++) {
			dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = arr[i][1] + min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1],dp[i-1][2])));
			dp[i][2] = arr[i][2] + min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
		}
		
		cout << tc << ". " << dp[N - 1][1] << "\n";
	}

	return 0;
}