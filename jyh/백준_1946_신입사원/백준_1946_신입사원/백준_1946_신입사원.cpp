#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() {
	FASTIO;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> v;
		

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}

		// 서류심사 기준
		sort(v.begin(), v.end());

		int minVal = v[0].second;
		int result = 1;

		for (int i = 0; i < v.size(); i++) {
			if (minVal > v[i].second) {
				minVal = v[i].second;
				result++;
			}
		}

		cout << result << endl;
	}

	return 0;
}