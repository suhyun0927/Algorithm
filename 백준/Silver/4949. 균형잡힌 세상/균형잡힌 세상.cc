#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

int main() {
	while (1) {
		string input;
		getline(cin, input);

		if (input.length() == 1 && input[0] == '.') break;

		stack<int>st;
		int flag = 0, last = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(' || input[i] == '[') {
				st.push(input[i]);
				continue;
			}
			
			if (input[i] == ')') {
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					flag = 1;
					break;
				}
				continue;
			}

			if (input[i] == ']') {
				if (!st.empty() && st.top() == '[') st.pop();
				else {
					flag = 1;
					break;
				}
				continue;
			}

			if (input[i] == '.' && i == input.length()-1) {
				last = 1;
				continue;
			}
		}

		if (!st.empty()) flag = 1;

		if (flag == 0 && last == 1) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
} 