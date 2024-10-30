#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;

	int cnt = 0;
	int res = 0;
	int flag = 0; // 인접한 쌍인지 여부

	stack<char>st;
	for (int j = 0; j < input.length(); j++) {
		if (input[j] == '(') {
			st.push('(');
			cnt++;
			res++;
			flag = 0;
		}
		else { // ) 일 때
			if (flag == 0) {
				st.pop();
				cnt--;
				res--;
				res += cnt;
				flag = 1;
			}
			else { // flag = 1 // 인접있었음
				st.pop();
				cnt--;
			}
		}
	}

	cout << res;

	return 0;
} 