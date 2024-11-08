#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

struct Node {
	int floor;
	int cnt;
};

int F, S, G, U, D;
int arr[1000001];
int dx[2];
queue<Node>q;

void bfs() {
	// init
	for (int i = 1; i <= F; i++) arr[i] = 21e8;

	arr[S] = 0;
	q.push({ S, 0 });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next = now.floor + dx[i];

			if (next <= 0 || next > F) continue;
			if (arr[next] <= now.cnt + 1) continue;

			arr[next] = now.cnt + 1;
			q.push({ next, now.cnt + 1 });
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;

	dx[0] = U;
	dx[1] = D * (-1);

	bfs();
	
	if (arr[G] == 21e8) cout << "use the stairs";
	else cout << arr[G];

	return 0;
} 