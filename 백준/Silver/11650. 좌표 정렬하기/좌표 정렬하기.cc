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
	int x;
	int y;

	bool operator<(Node r) const {
		if (x == r.x) return y > r.y;
		return x > r.x;
	}
};

int N;
priority_queue<Node> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		int x, y;
		cin >> x >> y;
		
		pq.push({ x, y });
	}

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		cout << now.x << " " << now.y << "\n";
	}

	return 0;
}