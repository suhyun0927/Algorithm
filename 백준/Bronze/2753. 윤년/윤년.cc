#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;

	if (N % 4 == 0 && (N % 100 != 0 || N % 400 == 0)) cout << "1";
	else cout << "0";

	return 0;
}