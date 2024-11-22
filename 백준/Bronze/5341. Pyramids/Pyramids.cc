#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int N;
		cin >> N;

		if (N == 0) return 0;

		int res = 0;

		for (int i = 1; i <= N; i++) {
			res += i;
		}

		cout << res << "\n";
	}

	return 0;
}