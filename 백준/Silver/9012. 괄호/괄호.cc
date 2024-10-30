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

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		stack<char>st;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '(') {
				st.push('(');
			}
			else { // ) 일 때
				if (!st.empty() && st.top() == '(') {
					st.pop();
					continue;
				}
				st.push(')');
			}
		}

		if (st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
} 