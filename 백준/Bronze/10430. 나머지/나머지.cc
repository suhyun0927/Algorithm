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
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << "\n";
	cout << ((a%c) + (b%c)) % c << "\n";
	cout << (a * b) % c << "\n";
	cout << ((a%c) * (b%c)) % c << "\n";

	return 0;
}