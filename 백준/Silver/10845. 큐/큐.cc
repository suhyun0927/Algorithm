#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char input[6];
        cin >> input;

        if (strcmp(input, "push") == 0) {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (strcmp(input, "pop") == 0) {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        else if (strcmp(input, "size") == 0) {
            cout << q.size() << "\n";
        }
        else if (strcmp(input, "empty") == 0) {
            cout << q.empty() <<"\n";
        }
        else if (strcmp(input, "front") == 0) {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if (strcmp(input, "back") == 0) {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }

    return 0;
}