#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	int res = 0;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		stack<char>st;

		for (int j = 0; j < input.length(); j++) {
			if (input[j] == 'A') {
				if (!st.empty() && st.top() == 'A') st.pop();
				else st.push('A');
				continue;
			}
			if (input[j] == 'B') {
				if (!st.empty() && st.top() == 'B') st.pop();
				else st.push('B');
				continue;
			}
		}

		if (st.empty()) res++;
	}
	
	cout << res;

	return 0;
} 