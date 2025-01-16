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

int N, M;
int arr[42];
int dp[41];
int res = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// init
	dp[0] = 1;
	dp[1] = 1;	
	dp[2] = 2;
	for (int i = 3;i <= 40;i++) dp[i] = dp[i - 2] + dp[i - 1];
	

	// input
	cin >> N >> M;

	arr[0] = 0;
	for (int i = 1;i <= M;i++) cin >> arr[i];
	arr[M + 1] = N + 1;

	for (int i = 0;i <= M;i++) {
		int tmp = arr[i + 1] - arr[i] - 1;
		if (tmp != 0) res *= dp[tmp];
	}

	cout << res;

	return 0;
}