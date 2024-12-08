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
char arr[3072][6144]; // 세로 3*1024, 가로 2*3072

void star(int n, int x, int y){
	if (n == 3) {
		arr[y][x] = '*';

		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';

		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
	}
	else{
		star(n / 2, x, y);
		star(n / 2, x - n / 2, y + n / 2);
		star(n / 2, x - n / 2 + n, y + n / 2);
	}
}

main(){
	cin >> N;

	// init
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 2 * N - 1; j++){
			arr[i][j] = ' ';
		}
	}

	star(N, N - 1, 0);

	// print
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 2 * N - 1; j++) cout << arr[i][j];
		cout << "\n";
	}

	return 0;
}
