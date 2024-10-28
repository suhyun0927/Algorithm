#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

struct Node {
	int id;
	int num;

	bool operator<(Node r) const {
		if (num == r.num) return id > r.id;
		else return num > r.num;
	}
};

deque<int>dq;
priority_queue<Node>pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l;

	cin >> n >> l;

	// input 받기
	for (int i = 0;i < n;i++) {
		int input;
		cin >> input;
		dq.push_back(input);
	}

	// pq 담기
	for (int i = 0;i < n;i++) {
		int start = i - l + 1;

		pq.push({i, dq[i]});

		while (pq.top().id <start) {
			pq.pop();
		}

		cout << pq.top().num << " ";
	}

	return 0;
}