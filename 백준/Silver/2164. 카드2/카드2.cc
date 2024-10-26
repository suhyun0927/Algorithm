#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) q.push(i);

    while (q.size() > 1) {
        q.pop();

        if (q.size() == 1) break;

        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    cout << q.front();

    return 0;
}