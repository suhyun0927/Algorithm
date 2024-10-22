#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[7][2];

int main() {
	int n, k, s, y;
	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		cin >> s >> y;
		arr[y][s]++;
	}

	int res = 0;
	for (int i = 1;i < 7;i++) {
		for (int j = 0;j < 2;j++) {
			if (arr[i][j] % k == 0) res += arr[i][j] / k;
			else res += (arr[i][j] / k + 1);
		}
	}

	cout << res;
	
	return 0;
}