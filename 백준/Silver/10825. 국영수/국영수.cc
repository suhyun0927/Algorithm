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
	string name;
	int kor;
	int eng;
	int math;

	bool operator<(Node r) const {
		if (kor == r.kor) {
			if (eng == r.eng) {
				if (math == r.math) return name > r.name;
				else return math < r.math;
			}
			else return eng > r.eng;
		}
		else return kor < r.kor;
	}
};

int N;
priority_queue<Node>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		string name;
		int kor;
		int eng;
		int math;

		cin >> name >> kor >> eng >> math;
		pq.push({ name, kor, eng, math });
	}

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		cout << now.name << "\n";
	}

	return 0;
}