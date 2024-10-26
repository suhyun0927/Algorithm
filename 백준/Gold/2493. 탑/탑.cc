#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

struct Node {
	int id;
	int num;
};

stack<Node>st1;
stack<Node>st2;
int arr[500001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		st1.push({i, tmp});
	}

	for (int i = n; i > 0; i--) {
		if (!st2.empty()) {
			while (!st2.empty() && st1.top().num > st2.top().num) {
				arr[st2.top().id] = st1.top().id;
				st2.pop();
			}
		}
		st2.push(st1.top());
		st1.pop();
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}