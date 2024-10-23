#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main() {
	string input;
	cin >> input;
	
	stack<char>now;
	stack<char>notnow;

	// init
	for (int i = 0;i < input.length();i++) now.push(input[i]);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		char ch;
		cin >> ch;

		if (ch == 'L') {
			if (!now.empty()) {
				char tmp = now.top();
				now.pop();
				notnow.push(tmp);
			}
		}
		else if (ch == 'D') {
			if (!notnow.empty()) {
				char tmp = notnow.top();
				notnow.pop();
				now.push(tmp);
			}
		}
		else if (ch == 'B') {
			if (!now.empty()) now.pop();
		}
		else { // ch == 'P'
			char tmp;
			cin >> tmp;
			now.push(tmp);
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

	return 0;
}