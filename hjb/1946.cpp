#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		int n, ans = 1; cin >> n;

		vector<pi>v1;
		for (int i = 0; i < n; i++)
		{
			int a, b; cin >> a >> b;
			v1.push_back({ a,b });
		}

		sort(v1.begin(), v1.end());

		int now = v1[0].second;
		for (int i = 1; i < v1.size(); i++) {
			if (now > v1[i].second) {
				ans++;
				now = v1[i].second;
			}
		}
		cout << ans << "\n";
	}
}
