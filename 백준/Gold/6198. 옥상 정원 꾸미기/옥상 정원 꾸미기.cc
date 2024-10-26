#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

stack<long long>st1;

int main() {
	int n;
	cin >> n;

	long long cnt = 0;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;

		while (!st1.empty() && st1.top() <= tmp) {
			st1.pop();
		}
		st1.push(tmp);
		cnt += st1.size()-1;
	}
	
	cout << cnt;
	

	return 0;
}