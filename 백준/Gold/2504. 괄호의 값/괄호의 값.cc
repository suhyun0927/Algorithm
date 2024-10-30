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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	stack<char>st;
	int res = 0, temp = 1;
	for (int i = 0;i < str.length();i++) {
		if (str[i] == '(') {
			st.push(str[i]);
			temp *= 2;
		}
		else if (str[i] == '[') {
			st.push(str[i]);
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top() == '[') {
				res = 0;
				break;
			}
			st.pop();
			if (str[i - 1] == '(') {
				res += temp;
				temp /= 2;
			}
			else temp /= 2;
		}
		else { // str[i] == ']'
			if (st.empty() || st.top() == '(') {
				res = 0;
				break;
			}
			st.pop();
			if (str[i - 1] == '[') {
				res += temp;
				temp /= 3;
			}
			else temp /= 3;
		}
	}

	if (!st.empty()) res = 0;
	
	cout << res;

	return 0;
}