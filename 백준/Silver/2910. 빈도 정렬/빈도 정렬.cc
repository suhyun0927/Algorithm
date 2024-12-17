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
	int cnt;
	int ord;
};

struct Dic {
	int num;
	int cnt;
	int order;

	bool operator<(Dic r)const {
		if (cnt == r.cnt) return order > r.order;
		return cnt < r.cnt;
	}
};

int N, C;
unordered_map<int, Node> um;
priority_queue<Dic>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N >> C;

	for (int i = 0;i < N;i++) {
		int input;
		cin >> input;

		if (um.count(input) == 0) um[input] = { 1, i };
		else um[input].cnt++;
	}

	for (auto iter : um) {
		pq.push({ iter.first, iter.second.cnt, iter.second.ord });
	}

	while (!pq.empty()) {
		Dic now = pq.top();
		pq.pop();
		for (int i = 0;i < now.cnt;i++) cout << now.num << " ";
	}

	return 0;
}