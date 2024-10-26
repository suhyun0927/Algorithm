#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        int arr[100000];
        stack<int> st;
        
        int n;
        cin >> n;

        if (n == 0) return 0;

        for (int i = 0; i < n; i++) cin >> arr[i];

        long long Max = -1;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                long long h = arr[st.top()];
                st.pop();

                long long w = i;
                if (!st.empty()) w = i - st.top() - 1;
                Max = max(Max, w * h);
            }
            st.push(i);
        }

        while (!st.empty()) {
            long long h = arr[st.top()];
            st.pop();

            long long w = n;

            if (!st.empty()) w = n - st.top() - 1;
            Max = max(Max, w * h);
        }

        cout << Max << "\n";
    }

    return 0;
}