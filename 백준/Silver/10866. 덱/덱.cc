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

int main() {
	int n;
	cin >> n;
	
	deque<int>dq;

	for (int i = 0;i < n;i++) {
		char input[11];
		cin >> input;

		if (strcmp(input, "push_front") == 0) {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (strcmp(input, "push_back") == 0) {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (strcmp(input, "pop_front") == 0) {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (strcmp(input, "pop_back") == 0) {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (strcmp(input, "size") == 0) {
			cout << dq.size() << "\n";
		}
		else if (strcmp(input, "empty") == 0) {
			cout << dq.empty() << "\n";
		}
		else if (strcmp(input, "front") == 0) {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		else if (strcmp(input, "back") == 0) {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}

	return 0;
}