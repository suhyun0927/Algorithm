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
using namespace std;

int N, M;
int arr[8];
int flag[8];
int correct[8];
string res;
unordered_map<string, int>um;

void checkDouble() {
	if (um.count(res) == 0) {
		um[res] = 1;
		for (int i = 0;i < M;i++) cout << arr[correct[i]] << " ";
		cout << "\n";
	}
	return;
}
void run(int level) {
	if (level == M) {
		checkDouble();
		return;
	}

	for (int i = 0;i < N;i++) {
		//if (flag[i] == 1) continue;
		//if (level != 0 && correct[level - 1] > i) continue;
		//flag[i] = 1;
		correct[level] = i;
		res.push_back(arr[i] + '0');
		run(level + 1);
		//flag[i] = 0;
		res.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	run(0);

	return 0;
}