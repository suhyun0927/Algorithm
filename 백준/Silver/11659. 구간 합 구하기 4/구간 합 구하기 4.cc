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
int now, s, e;
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);
	
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		cin >> now;
		dp[i] = dp[i - 1] + now;
	}

	for (int i = 0;i < M;i++) {
		cin >> s >> e;
		cout << dp[e] - dp[s - 1] << "\n";
	}

	return 0;
}