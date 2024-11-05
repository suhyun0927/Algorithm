#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int n;
	cin >> n;
	int y = 0, m = 0;

	for (int i = 0;i < n;i++) {
		int tmp;
		cin >> tmp;

		if (tmp>= 30 && tmp / 30 == 0) y += (tmp / 30) * 10;
		else y += (tmp / 30 + 1) * 10;
		
		if (tmp >= 60 && tmp / 60 == 0) m += (tmp / 60) * 15;
		else m += (tmp / 60 + 1) * 15;
	}

	if (y < m) cout << "Y " << y;
	else if (y == m) cout << "Y M " << y;
	else cout << "M " << m;

	return 0;
}