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

void hanoi(int n, int start, int to, int bypass){
	if (n == 1) cout << start << " " << to << "\n";
	else {
		hanoi(n - 1, start, bypass, to);
		cout << start << " " << to << "\n";
		hanoi(n - 1, bypass, to, start);
	}
}
int main() {
	cin >> N;
	cout << (1<<N) - 1 << "\n";
	hanoi(N, 1, 3, 2);
}