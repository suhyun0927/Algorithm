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
	int num;
	int age;
	string name;

	bool operator<(Node r) const {
		if (age == r.age) return num > r.num;
		return age > r.age;
	}
};

int N;
priority_queue<Node> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		int age;
		string name;

		cin >> age >> name;

		pq.push({ i, age, name });
	}

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		cout << now.age << " " << now.name << "\n";
	}

	return 0;
}