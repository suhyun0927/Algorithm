#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		string str[2];
		cin >> str[0] >> str[1];

		int dat[2][26] = { 0 };
		
		for (int j = 0;j < 2;j++) {
			for (int k = 0;k < 1000;k++) {
				if (str[j][k] == '\0') break;
				dat[j][str[j][k] - 'a']++;
			}
		}

		int flag = 0;
		for (int j = 0;j < 26;j++) {
			if (dat[0][j] != dat[1][j]) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}