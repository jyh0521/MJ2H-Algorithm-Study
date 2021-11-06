#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int cnt = 0;
	char prev = '_';
	for (int i = 0; i < s.size(); i++) {
		if (prev==s[i]) continue;
		prev = s[i];
		cnt++;
	}
	cout << cnt / 2;
	return 0;
}