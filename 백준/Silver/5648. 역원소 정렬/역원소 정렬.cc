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

int N;
vector<long long>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		string input;
		cin >> input;

		reverse(input.begin(), input.end());
		v.push_back(stoll(input));
	}

	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) cout << v[i] << "\n";

	return 0;
}