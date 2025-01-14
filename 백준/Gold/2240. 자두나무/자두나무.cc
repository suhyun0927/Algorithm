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

int T, W;
int arr[1001];
int dp[31][2][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T >> W;
	
	for (int i = 1; i <= T; i++)
		cin >> arr[i];


	for (int j = 0; j <= W; j++){
		for (int i = 1; i <= T; i++){
			if (j == 0) dp[j][0][i] = dp[j][0][i - 1] + (arr[i] == 1);
			else{
				dp[j][0][i] = max(dp[j][0][i - 1] + (arr[i] == 1), dp[j - 1][1][i - 1] + (arr[i] == 1));
				dp[j][1][i] = max(dp[j][1][i - 1] + (arr[i] == 2), dp[j - 1][0][i - 1] + (arr[i] == 2));
			}
		}
	}


	int ans = 0;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j <= W; j++){
			ans = max(ans, dp[j][i][T]);
		}
	}

	cout << ans;
	return 0;
}