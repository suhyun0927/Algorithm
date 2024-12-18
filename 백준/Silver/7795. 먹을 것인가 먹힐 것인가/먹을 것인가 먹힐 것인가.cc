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

int T, N, M;
int A[20001];
int B[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> T;

	for (int tc = 1;tc <= T; tc++) {
		// input
		cin >> N >> M;

		for (int i = 0;i < N;i++) cin >> A[i];
		for (int i = 0;i < M;i++) cin >> B[i];

		sort(B, B + M);

		// solve
		int res = 0;
		for (int i = 0;i < N;i++) {
			res += (lower_bound(B, B+M, A[i]) - B);
		}

		cout << res << "\n";
	}

	return 0;
}