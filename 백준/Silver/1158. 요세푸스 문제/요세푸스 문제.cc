#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n, k;
	vector<int>v;
	vector<int>res;
	cin >> n >> k;

	for (int i = 1;i <= n;i++) v.push_back(i);

	int num = 0, s = n;
	while (v.size() > 0) {
		num = (--num + k) % s;
		res.push_back(v[num]);
		v.erase(v.begin() + num);
		s--;
	}

	for (int i = 0;i < n;i++) {
		if (i == 0) cout << "<" << res[i];
		else cout << ", " << res[i];
	}
	cout << ">";

	return 0;
}