#include <bits/stdc++.h>
using namespace std;

int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	for (int i = 0; i + 1 < s.size(); i++)
		if (s[i] != s[i + 1]) ans++;

	if (ans % 2 != 0) cout << ans / 2 + 1;
	else cout << ans / 2;
}
