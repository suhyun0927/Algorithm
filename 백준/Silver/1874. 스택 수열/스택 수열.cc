#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int>st;
	queue<char>q;

	int now = 1;
	
	for (int i = 0;i < n;i++) {	
		int input;
		cin >> input;

		if (st.empty()) {
			st.push(now++);
			q.push('+');
		}
		while (st.top() != input) {
			if (now == n + 1) break;
			st.push(now++);
			q.push('+');
		}
		if (st.top() == input) {
			st.pop();
			q.push('-');
		}
	}

	if (st.size() != 0) cout << "NO";
	else {
		while (!q.empty()) {
			cout << q.front() << "\n";
			q.pop();
		}
	}

	return 0;
}