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

struct Node {
	string str;
	int len;

	bool operator<(Node r) const {
		if (len == r.len) return str < r.str;
		return len < r.len;
	}
};

int N;
vector<Node>v;
unordered_map<string, int>um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		string input;
		cin >> input;

		if (um.count(input) != 0) continue;

		int len = input.length();
		v.push_back({ input, len });
		um[input] = 1;
	}

	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) cout << v[i].str << "\n";

	return 0;
}