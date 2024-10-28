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

deque<string>dq;

int main() {
	int n, flag, er;
	cin >> n;
	
	for (int i = 0;i < n;i++) {
		dq.clear();
		
		string order;
		cin >> order;

		int cnt;
		cin >> cnt;

		string input;
		cin >> input;

		flag = 0; // 0일때 순방향, 1일때 역방향
		er = 0; // error 여부

		int start = 1;

		// 문자열 파싱하기
		for (int i = start;i < input.length();i++) {
			if (input[i] == ',' || input[i] == ']') {
				if(i != start) dq.push_back(input.substr(start, (i - start)));
				start = i + 1;
			}
		}

		//if (dq.empty()) er = 1;

		// 함수 조합
		for (int j = 0;j < order.length();j++) {
			if (order[j] == 'R') {
				flag = (flag + 1) % 2;
				continue;
			}

			if (order[j] == 'D') {
				if (dq.empty()) {
					er = 1;
					break;
				}

				if (flag == 0) dq.pop_front();
				else dq.pop_back();
			}
		}

		if (er == 1) cout << "error\n";
		else if (flag == 0) {
			cout << "[";
			while (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
		else if (flag == 1) {
			cout << "[";
			while (!dq.empty()) {
				cout << dq.back();
				dq.pop_back();
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}

	return 0;
}