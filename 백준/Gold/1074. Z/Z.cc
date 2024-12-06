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

int N,r,c;
int res;
int flag;

void recur(int sy, int sx, int level) {
	int fin = pow(2, N-level);
	int interval = fin / 2;

	if (flag == 1)return;

	if (sy == r && sx == c && level == N) {
		flag = 1;
		return;
	}

	if (r < sy || r >= sy + fin || c < sx || c >= sx + fin) {
		res += (fin * fin);
		return;
	}

	recur(sy, sx, level + 1);
	recur(sy, sx + interval, level + 1);
	recur(sy + interval, sx, level + 1);
	recur(sy + interval, sx + interval, level + 1);
	
}

int main() {

	cin >> N >> r >> c;

	recur(0, 0, 0);

	cout << res;

	return 0;
}