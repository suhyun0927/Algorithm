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

struct Node {
	long long num;
	int cnt;
};

int N;
unordered_map<long long, int>um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		long long input;
		cin >> input;

		if (um.count(input) == 0) um[input] = 1;
		else um[input]++;
	}

	Node res = { um.begin()->first, um.begin()->second };

	for (auto iter : um) {
		if (res.cnt < iter.second) {
			res = { iter.first, iter.second };
		}
		else if (res.cnt == iter.second) {
			if (res.num > iter.first) {
				res = { iter.first, iter.second };
			}
		}
	}

	cout << res.num;

	return 0;
}