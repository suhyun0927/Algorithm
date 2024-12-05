#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
using namespace std;

int N;
string str;

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;

		if (i == 0) str = tmp;

		for (int j = 0;j < str.length();j++) {
			if (str[j] == tmp[j]) continue;

			str[j] = '?';
		}
	}

	cout << str;

	return 0;
}