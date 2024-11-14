#include <iostream>
#include <vector>
#include <memory.h>
#include <stack>
using namespace std;

void solve();
void bfs(int start, bool visit[], vector<int> list[], bool truth[]);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}

void solve() {
	int N, K, true_person, number, party_number, count = 0;
	cin >> N >> K >> true_person;
	bool truth[51];
	bool visit[51];
	vector<int> party[51];
	vector<int> link[51];
	memset(truth, false, sizeof(truth));
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < true_person; i++) {
		cin >> number;
		truth[number] = true;
	}
	for (int i = 0; i < K; i++) {
		cin >> party_number;
		for (int j = 0; j < party_number; j++) {
			cin >> number;
			party[i].push_back(number);
		}
		for (int j = 0; j < party[i].size()-1; j++) {
			for (int k = j + 1; k < party[i].size(); k++) {
				link[party[i][j]].push_back(party[i][k]);
				link[party[i][k]].push_back(party[i][j]);
			}
		}
	}
	for (int i = 1; i <= 50; i++) {
		if (truth[i] == true) {
			bfs(i, visit, link, truth);
		}
	}
	for (int i = 0; i < K; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			if (truth[party[i][j]]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			count++;
		}
	}
	cout << count;
}

void bfs(int start, bool visit[], vector<int> link[], bool truth[]) {
	stack<int> s;
	s.push(start);
	visit[start] = true;
	while (!s.empty()) {
		int current = s.top();
		s.pop();
		for (int i = 0; i < link[current].size(); i++) {
			int next = link[current][i];
			if (!visit[next]) {
				s.push(next);
				visit[next] = true;
				truth[next] = true;
			}
		}
	}
}