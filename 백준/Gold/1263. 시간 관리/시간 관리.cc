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


struct Node {
	int t;
	int s;
};

int N, T, S;
int tmp = 0, pre = 0;
vector<Node>v;

bool cmp(const Node& a, const Node& b) {
	if (a.s > b.s) return true;
	else return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> T >> S;
		v.push_back({ T,S });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0;i < N;i++) {
		if (i != 0) {
			if (v[i].s >= tmp) pre += v[i].s - tmp;
			else if (tmp - v[i].s >= pre)pre = 0;
			else if (tmp - v[i].s < pre) pre -= tmp - v[i].s;
		}
		tmp = v[i].s - v[i].t;
	}

	if (pre > 0) tmp -= pre;

	if (tmp < 0)cout << "-1\n";
	else cout << tmp << "\n";

	return 0;
}