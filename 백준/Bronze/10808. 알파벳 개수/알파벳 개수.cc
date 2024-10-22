#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[26];

int main() {

	string S;
	cin >> S;

	for (int i = 0;i < S.length();i++) arr[S[i] - 'a']++;
	for (int i = 0;i < 26;i++) cout << arr[i] << " ";

	return 0;
}