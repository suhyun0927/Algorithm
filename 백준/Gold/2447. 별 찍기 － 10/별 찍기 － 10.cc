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

int N, K;
int three[9] = { 0,0,3,9,27,81,243,729,2187 };
char arr[3][3] = { {'*','*','*'},{'*', ' ', '*'},{'*','*','*'} };

int main() {

	cin >> N;

	// K 값 찾기
	int tmp = 1;
	while (tmp != N) {
		tmp *= 3;
		K++;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = K;k > 0;k--) {
				if (k == 1) {
					int ny = i % 3;
					int nx = j % 3;
					cout << arr[ny][nx];
				}
				else {
					int ny = i / three[k];
					int nx = j / three[k];

					if ((ny % 3) == 1 && (nx % 3) == 1) {
						cout << " ";
						break;
					}
				}
			}
		}

		cout << "\n";
	}


	return 0;
}