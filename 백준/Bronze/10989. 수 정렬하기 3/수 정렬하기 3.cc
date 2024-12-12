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
map<int, int>num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		int input;
		cin >> input;

		if (num.count(input) == 0) num[input] = 1;
		else num[input]++;
	}

	for (auto iter : num) {
		for (int i = 0;i < iter.second;i++) {
			cout << iter.first << "\n";
		}
	}

	return 0;
}