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

int T, N;
long long arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 1000000; i++) arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])%1000000009;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << arr[N] << "\n";
	}

	return 0;
}