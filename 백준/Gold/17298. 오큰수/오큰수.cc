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

stack<Node>st;
int arr[1000001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;

		while (!st.empty() && st.top().num < tmp) {
			arr[st.top().id] = tmp;
			st.pop();
		}

		st.push({i, tmp});
	}

	while (!st.empty()) {
		arr[st.top().id] = -1;
		st.pop();
	}
	
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}