#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0;i < tc;i++) {
		stack<char>now;
		stack<char>notnow;

		string input;
		cin >> input;

		for (int j = 0;j < input.length();j++) {
			if (input[j] == '-') {
				if (!now.empty()) {
					now.pop();
				}
			}
			else if (input[j] == '<') {
				if (!now.empty()) {
					char tmp = now.top();
					now.pop();
					notnow.push(tmp);
				}
			}
			else if (input[j] == '>') {
				if (!notnow.empty()) {
					char tmp = notnow.top();
					notnow.pop();
					now.push(tmp);
				}
			}
			else {
				now.push(input[j]);
			}
		}


		while (!now.empty()) {
			notnow.push(now.top());
			now.pop();
		}

		while (!notnow.empty()) {
			cout << notnow.top();
			notnow.pop();
		}
		cout << "\n";
	}

	return 0;
}