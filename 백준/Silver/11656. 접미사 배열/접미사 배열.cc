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
#include <map>
using namespace std;

string S;
vector<string>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;

	int len = S.length();

	for (int i = 0; i < len; i++) {
		v.push_back(S);
		S = S.substr(1, S.length());
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < len; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}