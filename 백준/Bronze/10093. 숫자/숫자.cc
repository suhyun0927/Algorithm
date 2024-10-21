#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	if (a == b) cout << "0\n";
	else cout << b - a - 1 << "\n";

	for (int i = a + 1;i < b;i++) cout << i << " ";

	return 0;
}