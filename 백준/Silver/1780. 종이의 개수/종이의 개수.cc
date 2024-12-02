#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N;
int board[2188][2188]; // 3^7 = 2187 
int res[3];

void recur(int sy, int sx, int level) {
    int fin = N / (pow(3, level));

    int first = board[sy][sx];

    for (int i = sy; i < sy + fin; i++) {
        for (int j = sx; j < sx + fin; j++) {
            if (board[i][j] != first) {
                int interval = fin / 3;
                recur(sy, sx, level + 1);
                recur(sy+interval, sx, level + 1);
                recur(sy+interval*2, sx, level + 1);
                recur(sy, sx+interval, level + 1);
                recur(sy+interval, sx+interval, level + 1);
                recur(sy+interval*2, sx+interval, level + 1);
                recur(sy, sx+interval*2, level + 1);
                recur(sy+interval, sx+interval*2, level + 1);
                recur(sy+interval*2, sx+interval*2, level + 1);

                return;
            }
        }
    }

    res[first + 1]++;
}

int main() {
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    recur(0,0,0);

    for (int i = 0; i < 3; i++) cout << res[i] << "\n";

    return 0;
}