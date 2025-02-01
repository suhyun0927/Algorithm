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

string s;
int result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	for (int i = 0;i < s.length();i++)
		if (s[i] != s[i + 1])
			result++;

	if (!result)
		cout << result;
	else cout << result / 2;

	return 0;
}