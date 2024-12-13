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
int arr[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) cin >> arr[i];

	sort(arr, arr + N, greater<>());

	for (int i = 0;i < N;i++) cout << arr[i] << "\n";

	return 0;
}