#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int>st;

	for (int i = 0;i < n;i++) {
		char ch[6];
		cin >> ch;

		if (strcmp(ch, "push") == 0) {
			int input;
			cin >> input;
			st.push(input);
		}
		else if (strcmp(ch, "pop") == 0) {
			if (st.empty()) cout << "-1\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (strcmp(ch, "size") == 0) {
			cout << st.size() << "\n";
		}
		else if (strcmp(ch, "empty") == 0) {
			cout << st.empty() << "\n";
		}
		else if (strcmp(ch, "top") == 0) {
			if (st.empty()) cout << "-1\n";
			else cout << st.top() << "\n";
		}
	}

	return 0;
}