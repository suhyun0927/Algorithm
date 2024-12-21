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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);

	char input;
	cin >> input;

	if (input == 'M') cout << "MatKor";
	else if (input == 'W') cout << "WiCys";
	else if (input == 'C') cout << "CyKor";
	else if (input == 'A') cout << "AlKor";
	else cout << "$clear";

	return 0;
}