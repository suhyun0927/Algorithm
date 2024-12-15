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
	string str;
	int len;
	int sum;

	bool operator<(Node r) const {
		if (len == r.len) {
			if (sum == r.sum) return str > r.str;
			return sum > r.sum;
		}
		return len > r.len;
	}
};

int N;
priority_queue<Node>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;

		int sum = 0;
		int len = str.length();
		for (int j = 0;j < len;j++) {
			if (str[j] >= '0' && str[j] <= '9') sum += str[j] - '0';
		}

		pq.push({ str, len, sum });
	}
	
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		cout << now.str << "\n";
	}

	return 0;
}